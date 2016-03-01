include "shared.thrift"
include "node_node.thrift"
include "node_client.thrift"
include "superNode.thrift"

namespace cpp csci_5105.PA1
namespace java csci_5105.PA1

/**
 * Contains all the local info:
 * 1. Identifier of local node (id, ip, port).
 * 2. ID of predecessor.
 * 3. ID of successor.
 * 4. FingerTable (store ids).
 * 5. Store the record for each hashed file.
 * 6. Node info for all nodes in the DHT system.
struct LocalInfo {
  1: shared.SingleNode node,
  2: i32 predecessorID,
  3: i32 successorID,
  4: list<i32> fingerTable,
  5: map<string, string> hash2file,
  6: shared.NodeList nodeList,
}
 */
