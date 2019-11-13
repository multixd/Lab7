//
//  AVLTree.hpp
//  Lab7
//
//  Created by Vincent Liang on 11/12/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <string>
#include <stdio.h>

struct Node {
    int value;
    int height;
    std::string str;
    Node* lchild = nullptr;
    Node* rchild = nullptr;
    Node* parent = nullptr;
    Node(const std::string&);
};

class AVLTree {
public:
    void insert(const std::string &);
    int balanceFactor(Node*);
    void printBalanceFactors();
    
private:
    Node* root;
    Node* findUnbalancedNode(Node*);
    void rotate(Node*);
    Node* rotateLeft(Node*);
    Node* rotateRight(Node*);
    void printBalanceFactors(Node *);
    int updateHeight(Node*);
};


#endif /* AVLTree_hpp */
