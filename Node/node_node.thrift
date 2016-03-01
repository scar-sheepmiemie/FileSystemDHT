include "shared.thrift"

namespace cpp csci_5105.PA1
namespace java csci_5105.PA1

service NodeService {
  i32 updateDHT(1:shared.SingleNode newNode),
  i32 transitFiles(1:shared.File file),
}
