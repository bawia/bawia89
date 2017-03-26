#include <iostream>
#include "mystack.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
using namespace std;

#define TEST false
int runCatchTests(int argc, char* const argv[])
{
    //catt the run method in catch
    return Catch::Session().run(argc, argv);
}
//        change true to false when you don’t want to
//        run the tests.  If that’s the case, the remainder of
//        main will run.

int main(int argc, char* argv[]){

        if (true)
        {
            return runCatchTests(argc, argv);
        }

    MyStack<int> charStack(5);
    charStack.pushStack(1);
    charStack.pushStack(2);
    cout << charStack.stackSize() << endl;
    charStack.popStack();
    cout << charStack.stackSize();
    cout << "Hello World!" << endl;
    return 0;
}
