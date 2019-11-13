//
//  AVLTree.hpp
//  Lab7
//
//  Created by Vincent Liang on 11/12/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include <string>
#include <stdio.h>
#include "Node.h"

class AVLTree {
public:
    void insert(const std::string &);
    int balanceFactor(Node*);
    void printBalanceFactors();
    
private:
    Node* root = NULL;
    Node* findUnbalancedNode(Node*);
    void rotate(Node*);
    void rotateLeft(Node*);
    void rotateRight(Node*);
    void replaceChild(Node*,Node*,Node*);
    void printBalanceFactors(Node *);
    void updateHeight(Node*);
};


#endif /* AVLTree_h */
