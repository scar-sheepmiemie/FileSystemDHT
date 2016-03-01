include "shared.thrift"

namespace cpp csci_5105.PA1
namespace java csci_5105.PA1

service ClientService {
  string readFile(1:string fileName),
  i32 writeFile(1:shared.File file),
}
