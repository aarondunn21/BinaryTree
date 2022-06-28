#include <iostream>
#include "BET.h"

int main() {
    BET t1;
    cout << t1.empty() << endl;
    BET a1("8 5 9 * +");
    cout << "size of Tree: " << a1.size() << endl;

    a1.printInfixExpression();
    a1.printPostfixExpression();
    a1.buildFromPostfix("2 3 4 * +");
    cout << a1.empty() << endl;
    a1.printInfixExpression();
    a1.printPostfixExpression();


    return 0;
}

//#include <iostream>
//#include <string>
//#include "BET.h"
//
//using namespace std;
//
//int main() {
//    string postfix;
//
//    // get a postfix expression
//    cout << "Enter the first postfix expression: ";
//    getline(cin, postfix);
//
//    // create a binary expression tree
//    BET bet1(postfix);
//    if (!bet1.empty()) {
//        cout << "Infix expression: ";
//        bet1.printInfixExpression();
//
//        cout << "Postfix expression: ";
//        bet1.printPostfixExpression();
//
//        cout << "Number of nodes: ";
//        cout << bet1.size() << endl;
//
//        cout << "Number of leaf nodes: ";
//        cout << bet1.leaf_nodes() << endl;
//
//        // test copy constructor
//        BET bet2(bet1);
//        cout << "Testing copy constructor: ";
//        bet2.printInfixExpression();
//
//        // test assignment operator
//        BET bet3;
//        bet3 = bet1;
//        cout << "Testing assignment operator: ";
//        bet3.printInfixExpression();
//    }
//
////    cout << "Enter a postfix expression (or \"quit\" to quit): ";
////    while (getline(cin, postfix)) {
////        if (postfix == "quit") {
////            break;
////        }
////        if (bet1.buildFromPostfix(postfix)) {
////            cout << "Infix expression: ";
////            bet1.printInfixExpression();
////
////            cout << "Postfix expression: ";
////            bet1.printPostfixExpression();
////
////            cout << "Number of nodes: ";
////            cout << bet1.size() << endl;
////
////            cout << "Number of leaf nodes: ";
////            cout << bet1.leaf_nodes() << endl;
////        }
////        cout << "Enter a postfix expression (or \"quit\" to quit): ";
////    }
//    return 0;
//}