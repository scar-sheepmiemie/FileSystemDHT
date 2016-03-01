namespace cpp csci_5105.PA1
namespace java csci_5105.PA1

/**
 * Store all the identifiers of a node, include id, ip and port.
 */
struct SingleNode{
  1:i32 id,
  2:string ip,
  3:i32 port,
}

/**
 * Store the identifiers of all node, and maintain the size of the list.
 */
struct NodeList {
  1:i32 maxSize,
  2:map<i32, SingleNode> id2node,
}

/**
 * Store the file name and file data.
 */
struct File {
  1:string fileName,
  2:string data,
}
