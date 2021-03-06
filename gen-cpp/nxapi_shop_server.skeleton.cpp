// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "nxapi_shop.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::nxapi_shop;

class nxapi_shopHandler : virtual public nxapi_shopIf {
 public:
  nxapi_shopHandler() {
    // Your initialization goes here
  }

  void ping(std::string& _return) {
    // Your implementation goes here
    printf("ping\n");
  }

  void Initialize(std::string& _return, const std::string& service_code, const int32_t server_no) {
    // Your implementation goes here
    printf("Initialize\n");
  }

  int32_t HeartBeat(const int32_t product_release_ticks) {
    // Your implementation goes here
    printf("HeartBeat\n");
  }

  void CheckBalance(NXAccountBalanceResult& _return, const NXUserId nexon_id) {
    // Your implementation goes here
    printf("CheckBalance\n");
  }

  void CheckBalanceEx(NXAccountBalanceResult& _return, const NXUserId nexon_id, const NXCashType::type cash_type) {
    // Your implementation goes here
    printf("CheckBalanceEx\n");
  }

  void PurchaseItems(NXPurchaseItemsResult& _return, const NXPurchaseItems& items) {
    // Your implementation goes here
    printf("PurchaseItems\n");
  }

  void InventoryCheck(NXInventoryCheckResult& _return, const NXGameId& game_id, const ENXShowInventory::type show_inventory, const ENXInventoryOrderType::type is_present) {
    // Your implementation goes here
    printf("InventoryCheck\n");
  }

  void InventoryPickup(NXInventoryPickupResult& _return, const NXAPITransactionId order_id, const NXProductNo product_no, const int32_t order_quntity, const std::string& extend_value) {
    // Your implementation goes here
    printf("InventoryPickup\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<nxapi_shopHandler> handler(new nxapi_shopHandler());
  shared_ptr<TProcessor> processor(new nxapi_shopProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

