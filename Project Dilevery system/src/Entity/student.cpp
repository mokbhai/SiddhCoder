#include <iostream>
#include "./User.cpp"
using namespace std;
namespace Entity
{
    class student : public User
    {
    private:
        /* data */
    public:
        string hostel_name;
        string block_room_no;
    };
}