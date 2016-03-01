#include "NodeService.h"
#include "ClientService.h" 
#include "NodeAdmin.h"
#include "md5.h"
#include <concurrency/ThreadManager.h>
#include <concurrency/PlatformThreadFactory.h>
#include <protocol/TBinaryProtocol.h>
#include <protocol/TMultiplexedProtocol.h>
#include <protocol/TProtocolDecorator.h>
#include <processor/TMultiplexedProcessor.h>
#include <server/TSimpleServer.h>
#include <server/TThreadPoolServer.h>
#include <server/TThreadedServer.h>
#include <server/TNonblockingServer.h>
#include <transport/TServerSocket.h>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <transport/TTransportUtils.h>

#include "dirent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unistd.h>
#include <math.h>

#define LINESIZE 1024
#define CONFIG "./../Node_Config"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

using namespace  ::csci_5105::PA1;

using namespace std;

/**
 * It's the information manager for node, which mainly has following functions:
 * 1. Store info for local host (id/ip/port) and SuperNode (ip/port).
 * 2. Maintain information of other nodes in node list.
 * 3. Maintain routing information, including pred/succ IDs and FingerTable.
 * 4. Maintain a file list, which contains file name and file hashcode.
 **/
class LocalInfo {
 public:
  SingleNode superNode;
  SingleNode node;
  int32_t predecessorID;
  int32_t successorID;
  int32_t enablePostJoin;
  vector<int32_t> fingerTable;
  map<string, string>  file2hash;
  NodeList nodeList;

  LocalInfo() {}
  /** 
   * Read config file to get identifies of local node and superNode:
   * 1. Local ip/port. Node needs to know its ip/port to set node ID.
   * 2. SuperNode ip/port. 
   * 3. A flag named Enable_PostJoin, which is used to test blocking join.
   *    If it's set to 0, current node will not send PostJoin.
   *    So other nodes will be blocked.
   **/
  LocalInfo(string config) {
    ifstream file(config.c_str());
    if (!file) {
      cout << "failed to open the file!" << endl; 
      return;
    }
    
    SingleNode* temp = new SingleNode();
    superNode = *temp;
    temp = new SingleNode();
    node = *temp;
    while (!file.eof()) {
      char buffer[LINESIZE];
      file.getline(buffer, LINESIZE);
      string line(buffer);

      int pos = line.find('=');
      if (pos == string::npos) return;
      string variable = line.substr(0, pos);
      if (variable == "Local_IP") {
        node.ip = line.substr(pos + 1);
      } else if (variable == "SuperNode_IP") {
        superNode.ip = line.substr(pos + 1);
      } else if (variable == "Local_Port") {
        node.port = atoi(line.substr(pos + 1).c_str());
      } else if (variable == "SuperNode_Port") {
        superNode.port = atoi(line.substr(pos + 1).c_str());
      } else if (variable == "Enable_PostJoin") {
        enablePostJoin = atoi(line.substr(pos + 1).c_str());
      }
      node.id = superNode.id = -1;
    }
    file.close();
  }

  ~LocalInfo(){
    SingleNode* temp = &superNode;
    delete temp;
    temp = &node;
    delete temp;
  }

  void findPredecessor() {
    map<int32_t, SingleNode>::iterator iter;
    iter = nodeList.id2node.find(node.id);
    map<int32_t, SingleNode>::reverse_iterator riter(iter);
    if (riter == nodeList.id2node.rend()) {
      riter = nodeList.id2node.rbegin();
    }
    predecessorID = riter->first;
  }

  void findSuccessor() {
    map<int32_t, SingleNode>::iterator iter;
    iter = nodeList.id2node.find(node.id);
    iter++;
    if (iter == nodeList.id2node.end()) {
      iter = nodeList.id2node.begin();
    }
    successorID = iter->first;
  }

  void buildFingerTable() {
    int32_t cur = 1, max = nodeList.maxSize;
    int32_t len = ceil(log(max)/log(2));
    vector<int> temp(len, 0);
    fingerTable.swap(temp);
    for (int32_t i = 0; i < len; i++) {
      map<int32_t, SingleNode>::iterator iter = nodeList.id2node.begin();
      int32_t temp = (cur + node.id) % max;
      while (iter != nodeList.id2node.end() && iter->first < temp) iter++;
      if (iter->first == node.id) {
        iter++;
      } 
      if (iter == nodeList.id2node.end()) {
        iter = nodeList.id2node.begin();
      }
      fingerTable[i] = iter->first;
      cur = cur << 1;
    }
    cout << endl;
  }

  string getHashCode(const string &file) {
	  return MD5(file).toString();
  }

  int32_t hash2fileID(const string &hash, const int mask) {
	  int prefixValue;
	  string hashPrefix = hash.substr(0, 6);
	  sscanf(hashPrefix.c_str(), "%x", &prefixValue);
	  return prefixValue % mask;
  }
};

class NodeServiceHandler : virtual public NodeServiceIf {
 public:
  LocalInfo localInfo;
  NodeServiceHandler(LocalInfo & li) {
    localInfo = li;
  }

  int32_t updateDHT(const  ::csci_5105::PA1::SingleNode& newNode) {
    printf("updateDHT\n");
    localInfo.nodeList.id2node[newNode.id] = newNode;
    localInfo.findPredecessor();
    localInfo.findSuccessor();
    localInfo.buildFingerTable();
    return 0;
  }

  /**
   * TODO:
   * Balance files distribution.
   **/
  int32_t transitFiles(const  ::csci_5105::PA1::File& file) {
    // Your implementation goes here
    printf("transitFiles\n");
    return 0;
  }

};

class ClientServiceHandler : virtual public ClientServiceIf {
 public:
  ClientServiceHandler() {
    // Your initialization goes here
  }

  void readFile(std::string& _return, const std::string& fileName) {
    // Your implementation goes here
    printf("readFile\n");
  }

  int32_t writeFile(const  ::csci_5105::PA1::File& file) {
    // Your implementation goes here
    printf("writeFile\n");
    return 0;
  }

};

void NodeInit(LocalInfo & localInfo) {
  boost::shared_ptr<TSocket> socket(new TSocket(localInfo.superNode.ip, localInfo.superNode.port));
     
  // Using TFramedTransport for nonblockingServer, for TSimpleServer it's TBufferedTransport.
  boost::shared_ptr<TTransport> transport(new TFramedTransport(socket)); 
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  NodeAdminClient client(protocol);
     
  transport->open();
  client.join(localInfo.nodeList, localInfo.node);
  while (localInfo.nodeList.id2node.empty()) {
    cout << "NACK: Another node is joining!" << endl;
    sleep(5);
    client.join(localInfo.nodeList, localInfo.node);
  }
  cout << "Node list:" << endl;
  map<int32_t, SingleNode>::iterator citer = localInfo.nodeList.id2node.begin();
  for (;citer != localInfo.nodeList.id2node.end(); citer++) {
    cout << citer->first << endl;
  }
  map<int32_t, SingleNode>::iterator iter = localInfo.nodeList.id2node.begin();
  for (;iter != localInfo.nodeList.id2node.end(); iter++) {
    SingleNode temp = iter->second;
    if (temp.ip == localInfo.node.ip && temp.port == localInfo.node.port) {
      localInfo.node.id = temp.id;
      break;
    }
  }

  localInfo.findPredecessor();
  localInfo.findSuccessor();
  cout << "Local:" << localInfo.node.id << endl;
  cout << "Pred:" << localInfo.predecessorID << endl;
  cout << "Succ:" << localInfo.successorID << endl;
  localInfo.buildFingerTable();
  // inform other nodes to update DHT.
  for (iter = localInfo.nodeList.id2node.begin(); iter != localInfo.nodeList.id2node.end(); iter++) {
    if (iter->first != localInfo.node.id) {
      boost::shared_ptr<TSocket> up_socket(new TSocket(iter->second.ip, iter->second.port));
      boost::shared_ptr<TTransport> up_transport(new TFramedTransport(up_socket)); 
      boost::shared_ptr<TProtocol> up_protocol(new TBinaryProtocol(up_transport));
      boost::shared_ptr<TMultiplexedProtocol> m_up_protocol(new TMultiplexedProtocol(up_protocol, "NodeService"));
      NodeServiceClient up_client(m_up_protocol);
      up_transport->open();
      up_client.updateDHT(localInfo.node);
      up_transport->close();
    }
  }
  if (1 == localInfo.enablePostJoin) client.postJoin();
  transport->close();
}

int main(int argc, char **argv) {
  // Initialization with config and superNode.
  LocalInfo li(CONFIG);
  NodeInit(li);
  cout << "SuperNode, " << li.superNode.ip << ":" << li.superNode.port << endl;
  cout << "LocalNode, " << li.node.ip << ":" << li.node.port << endl;
  
  // Start service.
  shared_ptr<NodeServiceHandler> nodeHandler(new NodeServiceHandler(li));
  shared_ptr<ClientServiceHandler> clientHandler(new ClientServiceHandler());
  shared_ptr<TProcessor> nodeProcessor(new NodeServiceProcessor(nodeHandler));
  shared_ptr<TProcessor> clientProcessor(new ClientServiceProcessor(clientHandler));
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  // Enable multiple services with a single port.
  shared_ptr<TMultiplexedProcessor> processor(new TMultiplexedProcessor());
  processor->registerProcessor("NodeService", nodeProcessor);
  processor->registerProcessor("ClientService", clientProcessor);

  // using thread pool with maximum 15 threads to handle incoming requests
  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
  shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();
  TNonblockingServer server(processor, protocolFactory, li.node.port, threadManager);
  server.serve();
  return 0;
}

