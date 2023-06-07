#include <iostream>
#include "../Enum/OrderStatus.cpp"
using namespace std;
using namespace Enum;
namespace Entity
{
    class Order
    {
    private:
        /* data */
    public:
        string orderID;
        string orderedItem;
        OrderStatus status;
    };
}