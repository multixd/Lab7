//
//  AVLTree.cpp
//  Lab7
//
//  Created by Vincent Liang on 11/12/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#include "AVLTree.hpp"
#include <iostream>

Node::Node(const std::string&aString) {
    value = 0;
    str = aString;
}

int AVLTree::balanceFactor(Node* curr) {
    int l = -1;
    int r = -1;
    if(curr->lchild != nullptr) {
        l = curr->lchild->height;
    }
    if(curr->rchild != nullptr) {
        r = curr->rchild ->height;
    }
    return l-r;
}

int AVLTree::updateHeight(Node* curr) {
    int l = -1;
    int r = -1;
    
    if(curr->lchild != nullptr) {
        l = curr->lchild->height;
    }
    if(curr->rchild != nullptr) {
        r = curr->rchild ->height;
    }
    
    if(l>r) {
        return 1+l;
    }
    return 1+r;
}

void AVLTree::printBalanceFactors(){
    printBalanceFactors(root);
}

void AVLTree::printBalanceFactors(Node* curr) {
    if(curr == nullptr) {
        return;
    }
    printBalanceFactors(curr->lchild);
    std::cout << curr->str << "(" << balanceFactor(curr) << ")";
    std::cout << " ,";
    printBalanceFactors(curr->rchild);
}


Node* AVLTree::findUnbalancedNode(Node* curr) {
    if(curr == nullptr) {
        return nullptr;
    }
    int balance = balanceFactor(curr);
    if(balance > 1 || balance < -1) {
        return curr;
    }
    
    return findUnbalancedNode(curr->parent);
}

void AVLTree::rotate(Node *curr){
    
}

void AVLTree::insert(const std::string &astring){
    Node* add = new Node( astring);
    if(root == nullptr) {
        root = add;
        return;
    }
    
    Node* curr = root;

    
    while(curr != nullptr) {
        if(curr->value < add ->value && curr->lchild != nullptr ) {
            curr = curr->lchild;
        }
        else if (curr->value < add ->value && curr->lchild == nullptr) {
            curr->lchild = add;
            add->parent = curr;
            break;
        }
        else if (curr->rchild != nullptr){
            curr = curr->rchild;
        }
        else {
            curr->rchild = add;
            add->parent = curr;
            break;
        }
    }
    
    
}
