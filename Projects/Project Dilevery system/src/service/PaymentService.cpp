#include <iostream>
#include "../Entity/Payment.cpp"
using namespace std;
using namespace Entity;
namespace Service
{
    class PaymentService
    {
    private:
        /* data */
    public:
        Payment makePayment();
        Payment getPayment();
    };    
}