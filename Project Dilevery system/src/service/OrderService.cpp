#include <iostream>
#include "../Entity/Order.cpp"
#include "../Enum/OrderStatus.cpp"

using namespace Enum;
using namespace std;
using namespace Entity;

namespace Service
{
    class OrderService
    {
    private:
        /* data */
    public:
        Order updateStatus(OrderStatus status);
        Order orderList();
        Order placeOrder();
    };
    OrderStatus updateStatus(OrderStatus status, string OrderID)
    {
        
    }
    Order orderList(string userID)
    {
    }
    Order placeOrder(string userID)
    {
    }
}