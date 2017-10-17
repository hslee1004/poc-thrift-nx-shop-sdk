namespace cpp nxapi_shop

typedef i64 NXUserId
typedef string NXGameId
typedef i32 NXProductNo
typedef string NXMerchantOrderId
typedef i32 NXAPITransactionId
  
enum NXCashType
{
  kNXDefault = 0,
  kNXCredit = 1,
  kNXPrepaid = 2,
  kNXCoupon = 3,
  kNXNexonCash = 13001,
  kNXSera = 13003,
  kNXGamePoint = 9999
}

enum NXAPIResultsType
{
  kNone = 0,
  kSuccess = 1,
  kFail = 2
}

struct NXAPIResult
{
  1: NXAPIResultsType response,
  2: optional string response_value
}

struct NXCash
{
  1: NXCashType cash_type,
  2: i32 cash_amount
}

struct NXAccountBalance
{
  1: NXUserId nexon_id,
  2: list<NXCash> balances
}

enum NXAccountBalanceResultCode
{
  kNone = 0,
  kOK = 1,
  kDBError = 99,
  kInServerMaintenance = 255,
  kBlockedUser = 12001,
  kUserNotExist = 12002
}

struct NXAccountBalanceResult
{
  1: NXAccountBalanceResultCode result,
  2: NXAccountBalance balance,
}

struct NXItem
{
  1: i32 product_no,
  2: i32 product_price,
  3: optional i32 count
}

enum NXPurchaseReason
{
  kNXReasonDefault = 0,
  kNXReasonGameClient = 1,
  kNXReasonWeb = 2,
  kNXReasonGameClientInPCCafe = 3,
  kNXReasonWebInPCCafe = 4
}

enum NXPaymentRuleId
{
  kNXRuleAll = 1,
  kNXRuleAllowRefund = 2,
  kNXRuleNoRefund = 3
}

enum NXPurchaseItemCode
{
  kNXRuleAll = 1,
  kNXRuleAllowRefund = 2,
  kNXRuleNoRefund = 3
}

struct NXPurchaseItems
{
  1: string user_ip,
  2: NXPurchaseReason reason,
  3: NXGameId gameId,
  4: NXUserId nexon_id,
  5: optional i32 nexon_oid,
  6: optional string user_name,
  7: optional i32 user_age,
  8: NXMerchantOrderId merchant_order_id,
  9: NXCashType payment_type,
  10: NXPaymentRuleId payment_rule_id,
  11: i32 total_amount,
  12: list<NXItem> items
}

struct NXPurchaseItemsResult
{
  1: NXMerchantOrderId merchant_order_id,
  2: NXAPITransactionId transaction_id,
  3: NXPaymentRuleId payment_rule_id,
  4: i32 total_amount,
  5: list<NXItem> items,
  6: string extend_value
}

enum ENXShowInventory
{
  kNXShowInvenNone = 0,
  kNXShowInvenDisplayToUser = 10,
  kNXShowInvenHiddenToUser = 30
}

enum ENXInventoryOrderType
{
  kNXInvenOrderTypeNormal = 0,
  kNXInvenOrderTypePresent = 1,
  kNXInvenOrderTypeBoth = 2, 
  kNXInvenOrderTypeAll = 3 
}

struct NXInventoryPickupResult
{
  1: i32 result,
  2: NXAPITransactionId order_no,
  3: NXProductNo product_no,
  4: i32 order_quantity,
  5: string extend_value
}

struct NXInventoryCheckResult
{
  1: i32 result,
  2: ENXInventoryOrderType order_type,
  3: i32 total_count
}

service nxapi_shop
{
  string ping(),
  string Initialize(1:string service_code, 2:i32 server_no),
  i32 HeartBeat(1:i32 product_release_ticks),
  NXAccountBalanceResult CheckBalance(1: NXUserId nexon_id),
  NXAccountBalanceResult CheckBalanceEx(1: NXUserId nexon_id, 2:NXCashType cash_type),
  NXPurchaseItemsResult PurchaseItems(1: NXPurchaseItems items),
  NXInventoryCheckResult InventoryCheck(1:NXGameId game_id, 2:ENXShowInventory show_inventory, 3:ENXInventoryOrderType is_present),
  NXInventoryPickupResult InventoryPickup(1:NXAPITransactionId order_id, 2:NXProductNo product_no, 3:i32 order_quntity, 4:string extend_value)
}



































