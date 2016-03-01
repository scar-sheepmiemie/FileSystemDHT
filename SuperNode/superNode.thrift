include "shared.thrift"

namespace cpp csci_5105.PA1
namespace java csci_5105.PA1
/*
enum State {
  INIT = 1,
  ADDING = 2,
  WORKING = 3,
  BUSY = 4,
}
*/
service NodeAdmin {
  shared.NodeList join(1:shared.SingleNode newNode),
  i32 postJoin(),
}
