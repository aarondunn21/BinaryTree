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
    void makeEmpty(BinaryNode* &t);
    BinaryNode* clone(BinaryNode* &t);
    void postfixRecursion(BinaryNode* b);
    int treeSize(BinaryNode* b);
    int leaf_nodes(BinaryNode* b);

public:
    BET();
    explicit BET(const string& postfix);
    BET(const BET& x);
    ~BET();
    bool buildFromPostfix(const string& postfix);
    const BET& operator= (const BET& x);
    string GetTop();
    void printInfixExpression();
    void printPostfixExpression();
    bool empty();
    int size();
    int leaf_nodes();



};


#endif //BINARYTREE_BET_H

//BinaryNode(const string& theElement, BinaryNode *lt, BinaryNode *rt)
//        : element(theElement), left(lt), right(rt) {}