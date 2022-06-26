//
// Created by Aaron on 6/25/2022.
//

#ifndef BINARYTREE_BET_H
#define BINARYTREE_BET_H

#include <string>
#include <stack>

using namespace std;



class BET {
    struct BinaryNode{
        string element;
        struct BinaryNode *left;
        struct BinaryNode *right;
    };
    struct BinaryNode* newNode(string e){
        BinaryNode* node = new BinaryNode;
        node->element = e;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

private:
    stack<BinaryNode*> expStack;
    void infixRecursion(BinaryNode* b);
    void postfixRecursion(BinaryNode* b);


public:
    BET();
    explicit BET(const string& postfix);
    BET(const BET& x);
    ~BET();
    const BET& operator= (const BET& x);
    string GetTop();
    void PrintInfixExpression();
    void PrintPostfixExpression();
    bool empty();



};


#endif //BINARYTREE_BET_H

//BinaryNode(const string& theElement, BinaryNode *lt, BinaryNode *rt)
//        : element(theElement), left(lt), right(rt) {}