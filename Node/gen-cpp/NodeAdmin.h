/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef NodeAdmin_H
#define NodeAdmin_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "superNode_types.h"

namespace csci_5105 { namespace PA1 {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class NodeAdminIf {
 public:
  virtual ~NodeAdminIf() {}
  virtual void join( ::csci_5105::PA1::NodeList& _return, const  ::csci_5105::PA1::SingleNode& newNode) = 0;
  virtual int32_t postJoin() = 0;
};

class NodeAdminIfFactory {
 public:
  typedef NodeAdminIf Handler;

  virtual ~NodeAdminIfFactory() {}

  virtual NodeAdminIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(NodeAdminIf* /* handler */) = 0;
};

class NodeAdminIfSingletonFactory : virtual public NodeAdminIfFactory {
 public:
  NodeAdminIfSingletonFactory(const boost::shared_ptr<NodeAdminIf>& iface) : iface_(iface) {}
  virtual ~NodeAdminIfSingletonFactory() {}

  virtual NodeAdminIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(NodeAdminIf* /* handler */) {}

 protected:
  boost::shared_ptr<NodeAdminIf> iface_;
};

class NodeAdminNull : virtual public NodeAdminIf {
 public:
  virtual ~NodeAdminNull() {}
  void join( ::csci_5105::PA1::NodeList& /* _return */, const  ::csci_5105::PA1::SingleNode& /* newNode */) {
    return;
  }
  int32_t postJoin() {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _NodeAdmin_join_args__isset {
  _NodeAdmin_join_args__isset() : newNode(false) {}
  bool newNode :1;
} _NodeAdmin_join_args__isset;

class NodeAdmin_join_args {
 public:

  NodeAdmin_join_args(const NodeAdmin_join_args&);
  NodeAdmin_join_args& operator=(const NodeAdmin_join_args&);
  NodeAdmin_join_args() {
  }

  virtual ~NodeAdmin_join_args() throw();
   ::csci_5105::PA1::SingleNode newNode;

  _NodeAdmin_join_args__isset __isset;

  void __set_newNode(const  ::csci_5105::PA1::SingleNode& val);

  bool operator == (const NodeAdmin_join_args & rhs) const
  {
    if (!(newNode == rhs.newNode))
      return false;
    return true;
  }
  bool operator != (const NodeAdmin_join_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NodeAdmin_join_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class NodeAdmin_join_pargs {
 public:


  virtual ~NodeAdmin_join_pargs() throw();
  const  ::csci_5105::PA1::SingleNode* newNode;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _NodeAdmin_join_result__isset {
  _NodeAdmin_join_result__isset() : success(false) {}
  bool success :1;
} _NodeAdmin_join_result__isset;

class NodeAdmin_join_result {
 public:

  NodeAdmin_join_result(const NodeAdmin_join_result&);
  NodeAdmin_join_result& operator=(const NodeAdmin_join_result&);
  NodeAdmin_join_result() {
  }

  virtual ~NodeAdmin_join_result() throw();
   ::csci_5105::PA1::NodeList success;

  _NodeAdmin_join_result__isset __isset;

  void __set_success(const  ::csci_5105::PA1::NodeList& val);

  bool operator == (const NodeAdmin_join_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const NodeAdmin_join_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NodeAdmin_join_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _NodeAdmin_join_presult__isset {
  _NodeAdmin_join_presult__isset() : success(false) {}
  bool success :1;
} _NodeAdmin_join_presult__isset;

class NodeAdmin_join_presult {
 public:


  virtual ~NodeAdmin_join_presult() throw();
   ::csci_5105::PA1::NodeList* success;

  _NodeAdmin_join_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class NodeAdmin_postJoin_args {
 public:

  NodeAdmin_postJoin_args(const NodeAdmin_postJoin_args&);
  NodeAdmin_postJoin_args& operator=(const NodeAdmin_postJoin_args&);
  NodeAdmin_postJoin_args() {
  }

  virtual ~NodeAdmin_postJoin_args() throw();

  bool operator == (const NodeAdmin_postJoin_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const NodeAdmin_postJoin_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NodeAdmin_postJoin_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class NodeAdmin_postJoin_pargs {
 public:


  virtual ~NodeAdmin_postJoin_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _NodeAdmin_postJoin_result__isset {
  _NodeAdmin_postJoin_result__isset() : success(false) {}
  bool success :1;
} _NodeAdmin_postJoin_result__isset;

class NodeAdmin_postJoin_result {
 public:

  NodeAdmin_postJoin_result(const NodeAdmin_postJoin_result&);
  NodeAdmin_postJoin_result& operator=(const NodeAdmin_postJoin_result&);
  NodeAdmin_postJoin_result() : success(0) {
  }

  virtual ~NodeAdmin_postJoin_result() throw();
  int32_t success;

  _NodeAdmin_postJoin_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const NodeAdmin_postJoin_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const NodeAdmin_postJoin_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NodeAdmin_postJoin_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _NodeAdmin_postJoin_presult__isset {
  _NodeAdmin_postJoin_presult__isset() : success(false) {}
  bool success :1;
} _NodeAdmin_postJoin_presult__isset;

class NodeAdmin_postJoin_presult {
 public:


  virtual ~NodeAdmin_postJoin_presult() throw();
  int32_t* success;

  _NodeAdmin_postJoin_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class NodeAdminClient : virtual public NodeAdminIf {
 public:
  NodeAdminClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  NodeAdminClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void join( ::csci_5105::PA1::NodeList& _return, const  ::csci_5105::PA1::SingleNode& newNode);
  void send_join(const  ::csci_5105::PA1::SingleNode& newNode);
  void recv_join( ::csci_5105::PA1::NodeList& _return);
  int32_t postJoin();
  void send_postJoin();
  int32_t recv_postJoin();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class NodeAdminProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<NodeAdminIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (NodeAdminProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_join(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_postJoin(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  NodeAdminProcessor(boost::shared_ptr<NodeAdminIf> iface) :
    iface_(iface) {
    processMap_["join"] = &NodeAdminProcessor::process_join;
    processMap_["postJoin"] = &NodeAdminProcessor::process_postJoin;
  }

  virtual ~NodeAdminProcessor() {}
};

class NodeAdminProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  NodeAdminProcessorFactory(const ::boost::shared_ptr< NodeAdminIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< NodeAdminIfFactory > handlerFactory_;
};

class NodeAdminMultiface : virtual public NodeAdminIf {
 public:
  NodeAdminMultiface(std::vector<boost::shared_ptr<NodeAdminIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~NodeAdminMultiface() {}
 protected:
  std::vector<boost::shared_ptr<NodeAdminIf> > ifaces_;
  NodeAdminMultiface() {}
  void add(boost::shared_ptr<NodeAdminIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void join( ::csci_5105::PA1::NodeList& _return, const  ::csci_5105::PA1::SingleNode& newNode) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->join(_return, newNode);
    }
    ifaces_[i]->join(_return, newNode);
    return;
  }

  int32_t postJoin() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->postJoin();
    }
    return ifaces_[i]->postJoin();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class NodeAdminConcurrentClient : virtual public NodeAdminIf {
 public:
  NodeAdminConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  NodeAdminConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void join( ::csci_5105::PA1::NodeList& _return, const  ::csci_5105::PA1::SingleNode& newNode);
  int32_t send_join(const  ::csci_5105::PA1::SingleNode& newNode);
  void recv_join( ::csci_5105::PA1::NodeList& _return, const int32_t seqid);
  int32_t postJoin();
  int32_t send_postJoin();
  int32_t recv_postJoin(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

}} // namespace

#endif
