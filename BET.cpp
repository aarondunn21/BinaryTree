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
//default constructor

BET::BET(const string &postfix) {
    stringstream ss;
    string temp;
    ss << postfix;
    //take each element in string separately

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
            //check if operator and use previous operators
        }
        else{
            BinaryNode *a = newNode(temp);
            expStack.push(a);
            //add to stack if operand
        }

    }
}

BET::BET(const BET & x) {
    stack<BinaryNode*> temp;
    temp = x.expStack;
    this->expStack = temp;
    //deep copy constructor
}

bool BET::buildFromPostfix(const string &postfix) {
    if(!empty()){
        makeEmpty(expStack.top());
        expStack.pop();
    }
    //empty out current tree

    BET temp(postfix);
    expStack = temp.expStack;
    //create new tree

    return true;
}

const BET &BET::operator=(const BET & x) {
    BinaryNode* temp1 = x.expStack.top();
    BinaryNode* temp2;
    temp2 = clone(temp1);
    expStack.push(temp2);
    return *this;
    //assignment overload using private helper clone function
}

void BET::printInfixExpression() {
    BinaryNode* temp = expStack.top();
    infixRecursion(temp);
    cout << endl;
}

void BET::printPostfixExpression() {
    BinaryNode* temp = expStack.top();
    postfixRecursion(temp);
    cout << endl;
}
//use recursion helper functions to traverse tree and print

void BET::infixRecursion(BinaryNode* b) {
    if(b != nullptr){
        infixRecursion(b->left);
        cout << b->element << endl;
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
//recursive fucntions to traverse tree and print elements

bool BET::empty() {
    if(expStack.empty()){
        return true;
    }
    else return false;
}
//check if tree is empty

BET::~BET() {
    while(!expStack.empty()){
        expStack.pop();
    }
}
//destructor

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
    int size = 0;
    size += treeSize(expStack.top());
    return size;
}
//use recursion traversal to find size of tree

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
    t->element = " ";
}
//use recursion traversal to find amount of leafs


BET::BinaryNode *BET::clone(BET::BinaryNode *&t) {
    BinaryNode* temp = new BinaryNode;
    temp = t;
    return temp;
}
//make new pointer to point to copy of passed in node.


