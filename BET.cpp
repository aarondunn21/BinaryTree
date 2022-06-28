//
// Created by Aaron on 6/25/2022.
//

#include "BET.h"
#include "stack"
#include "sstream"
#include "iostream"

using namespace std;

BET::BET() {
    BinaryNode* a1;
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
    stack<BinaryNode*> temp;
    temp = x.expStack;
    this->expStack = temp;
}

bool BET::buildFromPostfix(const string &postfix) {
    if(!empty()){
        makeEmpty(expStack.top());
        expStack.pop();
    }

    BET temp(postfix);
    expStack = temp.expStack;

    return true;
}

const BET &BET::operator=(const BET & x) {
    stack<BinaryNode*> temp;
    temp = x.expStack;
    this->expStack = temp;
    return *this;
}

void BET::printInfixExpression() {
    BinaryNode* temp = expStack.top();
//    stack<BinaryNode*> tempStack = expStack;
//    string postfixString = ;
//    while(!tempStack.empty()){
//        postfixString += tempStack.top()->element;
//        tempStack.pop();
//    }
//    cout << postfixString;
    infixRecursion(temp);
    cout << endl;
}

void BET::printPostfixExpression() {
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

int BET::treeSize(BinaryNode* b) {
    if(b == nullptr){
        return 0;
    }
    else{
        return 1 + treeSize(b->left) + treeSize(b->right);
        //recurse through children and add 1 for root
    }
}

int BET::size() {
//    BinaryNode* temp;
//    stack<BinaryNode*> tempStack = expStack;
    int size = 0;
    size += treeSize(expStack.top());
    return size;
}

int BET::leaf_nodes(BET::BinaryNode *b) {
    if(b == nullptr){
        return 0;
    }
    else{
        if(b->left == nullptr && b->left == nullptr){
            return 1;
        }
        else{
            return leaf_nodes(b->left) + leaf_nodes(b->right);
        }
        //recurse through children to find leafs
    }
}

int BET::leaf_nodes() {
    int size = 0;
    size += leaf_nodes(expStack.top());
    return size;
}

void BET::makeEmpty(BET::BinaryNode* &t) {
    t->left = nullptr;
    t->right = nullptr;
}

BET::BinaryNode *BET::clone(BET::BinaryNode *&t) {
    BinaryNode* temp = new BinaryNode;
    temp = t;
    return temp;
}











