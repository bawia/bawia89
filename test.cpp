//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cstring>
#include "MyStack.h"
#include "dlList.h"

TEST_CASE("Double Linked List Class", "[DLL}"){

        SECTION ( " Default constructor for DLL class ")
        {
            DLList <int> st;
            REQUIRE(st.getSize()==0);
        }

        SECTION ( " Constructor with head ")
        {
            DLList <int> in;
            in.insertNode(1);
            in.insertNode(2);
            REQUIRE(in.getSize()==2);
        }

//          SECTION ( " Copy Constructor "){

//          }
//          SECTION ( " Add "){

//          }
//          SECTION ( " addToFront "){

//          }
//          SECTION ( " getElement "){

//          }
//          SECTION ( " size "){

//          }
//          SECTION ( " remove "){

//          }
//          SECTION ( " [] operator "){

//          }
//          SECTION ( " assignment operator "){

//          }
}
//    SECTION(" Constuctor for MyStack ")
//     {
//         MyStack <int> St(5);
//         REQUIRE(St.getCapa()== 5);
//         REQUIRE(St.stackSize()== 0);
//     }

//    SECTION(" Push Element ")
//    {
//        MyStack <int> pushSt(10);
//        pushSt.pushStack(1);
//        pushSt.pushStack(2);
//        REQUIRE(pushSt.getCapa()==10);
//        REQUIRE(pushSt.stackSize()==2);
//    }

//    SECTION(" Pop element ")
//    {
//        MyStack <int> popSt(3);
//        for (int i =0; i < 3; i++)
//        {
//            popSt.pushStack(i);
//        }
//        REQUIRE(popSt.stackSize()==3);
//        popSt.popStack();
//        REQUIRE(popSt.stackSize()==2);
//        popSt.popStack();
//        REQUIRE(popSt.stackSize()==1);
//    }
//    SECTION(" Empty check ")
//    {
//        MyStack <int> emptySt(5);
//        REQUIRE(emptySt.isEmpty()==true);
//    }
//    SECTION(" Get top element")
//    {
//        MyStack <int> topSt(3);
//        topSt.pushStack(5);
//        topSt.pushStack(23);
//        topSt.pushStack(33);

//        REQUIRE(topSt.getTop()==33);
//    }
//}
