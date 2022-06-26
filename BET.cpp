//
// Created by Aaron on 6/25/2022.
//

#include "BET.h"
#include "stack"
#include "sstream"
#include "iostream"

using namespace std;

BET::BET() {
    BinaryNode a1;
}

BET::BET(const string &postfix) {
    stringstream ss;
    string temp;
    //BinaryNode *a, *b, *c;

    ss << postfix;

    while(!ss.eof()){
        ss >> temp;
        if(temp == "+" || temp == "-" ||temp == "*"
        || temp == "/"){
            BinaryNode *a = newNode(temp);
            a->right = expStack.top();
            expStack.pop();
            a->left = expStack.top();
            expStack.pop();

            expStack.push(a);



//            BinaryNode *a = new BinaryNode(temp);
//            BinaryNode b = BinaryNode(expStack.top().element);
//            expStack.pop();
//            BinaryNode c = BinaryNode(expStack.top().element);
//            expStack.pop();
//            *a->right = b;
//            *a->left = c;
//            expStack.push(*a);
        }
        else{
            BinaryNode *a = newNode(temp);
            expStack.push(a);
        }

    }
}

BET::BET(const BET & x) {
    this->expStack  = x.expStack;
}

const BET &BET::operator=(const BET & x) {
    this->expStack = x.expStack;
    return *this;
}

void BET::PrintInfixExpression() {
    BinaryNode* temp = expStack.top();
    infixRecursion(temp);
    cout << endl;
}

void BET::PrintPostfixExpression() {
    BinaryNode* temp = expStack.top();
    postfixRecursion(temp);
    cout << endl;
}

string BET::GetTop() {
    return expStack.top()->element;
}

void BET::infixRecursion(BinaryNode* b) {
    if(b != nullptr){
        infixRecursion(b->left);
        cout << b->element << " ";
        infixRecursion(b->right);
    }
}

void BET::postfixRecursion(BET::BinaryNode *b) {
    if(b != nullptr){
        postfixRecursion(b->left);
        postfixRecursion(b->right);
        cout << b->element << " ";
    }
}

bool BET::empty() {
    if(expStack.empty()){
        return true;
    }
    else return false;
}

BET::~BET() {
    while(!expStack.empty()){
        expStack.pop();
    }
}










