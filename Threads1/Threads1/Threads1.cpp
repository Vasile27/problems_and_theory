// Threads1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include <vector>

using namespace std;

class port_state {};

// Macro that defines a particular state that is derived from class state
#define START_DEFINE_STATE(x) \
class x : port_state { \
    public: \
        ~x() {}; \
        static port_state *instance(); \
                                  \
        /* Play a trick to get a string that represents this state */ \
        const char *str_##x(void) { return __FUNCTION__ ; }; \
        const char *port_state_str(void) { \
            return ((str_##x()) + 4); \
        }; \
    \
        x() {} 

#define DEFINE_ENTER void enter()
#define DEFINE_EXIT void exit()

#define DEFINE_EVENT(event) \
        void event(); \

#define END_DEFINE_STATE(x) }; \
    port_state *x::instance() {\
    static port_state *this_state = NULL;\
    if(this_state == 0) {\
        this_state = new x();\
    }\
    return this_state;\
}

START_DEFINE_STATE(st_auto_sense_port_down);
DEFINE_ENTER;
DEFINE_EXIT;
DEFINE_EVENT(ev_port_up);
DEFINE_EVENT(ev_disable_auto_sense);
END_DEFINE_STATE(st_auto_sense_port_down);

int main()
{
 /*   st_auto_sense_port_down ob1;
    printf("%s", ob1.port_state_str());*/

    vector<int> v1{ 1, 2, 3 };

    vector<int>* p_v1 = &v1;

    for (const auto& it : (*p_v1))
    {
        cout << it << endl;
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
