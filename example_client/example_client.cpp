#include "stdafx.h"

#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "..\gen-cpp\nxapi_shop.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;
using namespace  ::nxapi_shop;

int _tmain(int argc, _TCHAR* argv[])
{
	boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	nxapi_shopClient client(protocol);

	try 
	{
		while(1)
		{
			transport->open();

			// ping test
			std::string rsPing;
			client.ping(rsPing);
			cout << "called ping: " << rsPing << endl;
			Sleep(1000);

			try 
			{
				//std::string rs;
				NXPurchaseItems purchase;
				purchase.nexon_id = 2588123;
				purchase.user_name = "nexon";
				for (int i = 0; i < 2; i++) 
				{
					NXItem item;
					item.product_no = 1000;
					item.product_price = 3000;
					purchase.items.push_back(item);
				}

				NXPurchaseItemsResult nxPurchaseResult;
				client.PurchaseItems(nxPurchaseResult, purchase);

			} 
			catch (...) 
			{
				cout << "InvalidOperation: " << endl;
			}

			transport->close();
		}
	} 
	catch (TException& tx) 
	{
		cout << "ERROR: " << tx.what() << endl;
	}

	return 0;
}

