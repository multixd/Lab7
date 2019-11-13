//
//  AVLTree.cpp
//  Lab7
//
//  Created by Vincent Liang on 11/12/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#include "AVLTree.h"
#include <iostream>

int AVLTree::balanceFactor(Node* curr) {
	if(curr == NULL) {
		return 0;
	}
    int l = -1;
    int r = -1;
    if(curr->lchild != NULL) {
        l = curr->lchild->height;
    }
    if(curr->rchild != NULL) {
        r = curr->rchild ->height;
    }
    return l-r;
}

void AVLTree::updateHeight(Node* curr) {
    int l = -1;
    int r = -1;
    
    if(curr->lchild != NULL) {
        l = curr->lchild->height;
    }
    if(curr->rchild != NULL) {
        r = curr->rchild ->height;
    }
    
    if(l>r) {
        curr->height = 1+l;
    }
    else {
		curr->height = 1+r;
	}
	
	if(curr->parent != NULL) {
		updateHeight(curr->parent);
	}
}


void AVLTree::printBalanceFactors(){
    printBalanceFactors(root);
    std::cout << std::endl;
}

void AVLTree::printBalanceFactors(Node* curr) {
    if(curr == NULL) {
        return;
    }
    printBalanceFactors(curr->lchild);
    std::cout << curr->str << "(" << balanceFactor(curr) << ")";
    std::cout << ", ";
    printBalanceFactors(curr->rchild);
}

 
Node* AVLTree::findUnbalancedNode(Node* curr) {
    if(curr == NULL) {
        return NULL;
    }
    int balance = balanceFactor(curr);
    if(balance > 1 || balance < -1) {
        return curr;
    }
    
    return findUnbalancedNode(curr->parent);
}

void AVLTree::rotate(Node *curr){
    int balance = balanceFactor(curr);
    
    if(balance == -2) {
		if(balanceFactor(curr->rchild) ==1) {
			rotateRight(curr->rchild);
		}
		rotateLeft(curr);
		return;
	}
	else if(balance == 2) {
		if(balanceFactor(curr->lchild) == -1) {
			rotateLeft(curr->lchild);
		}
		rotateRight(curr);
		return;
	}
}

void AVLTree::insert(const std::string &astring){
    Node* add = new Node( astring);
    if(root == NULL) {
        root = add;
        return;
    }
    
    Node* curr = root;

    
    while(curr != NULL) {
		if(curr->str == add->str) {
			return;
		}
        if(curr->str >= add ->str && curr->lchild != NULL ) {
            curr = curr->lchild;
        }
        else if (curr->str >=  add->str && curr->lchild == NULL) {
            curr->lchild = add;
            add->parent = curr;
            updateHeight(curr);
            break;
        }
        else if (curr->rchild != NULL){
            curr = curr->rchild;
        }
        else {
            curr->rchild = add;
            add->parent = curr;
            updateHeight(curr);
            break;
        }
    }
    
    Node* unbalance = findUnbalancedNode(add);
    while(unbalance != NULL) {
		rotate(unbalance);
		unbalance = findUnbalancedNode(curr);
	}
}

void AVLTree::replaceChild(Node* p, Node* curr, Node*child) {
	if(p->lchild == curr) {
		p->lchild = child;
		
	}
	else if(p->rchild == curr) {
		p->rchild = child;
	}
	else {
		std::cout << "Replace child not set" << std::endl;
	}
	
	if(child != NULL) {
		child->parent = p;
		
	}
	updateHeight(p);
}

void AVLTree::rotateRight(Node* node) {
	Node* leftRight = node->lchild->rchild;
	Node* left = node->lchild;
	if(node->parent!=NULL) {
		replaceChild(node->parent,node,left);
	}
	else {
		root = left;
		root->parent = NULL;
	}
	left->rchild = node;
	node->parent = left;
	node->lchild = leftRight;
	if(leftRight != NULL) {
		leftRight->parent = node;
		updateHeight(leftRight);
	}
	else {
		updateHeight(node);
	}
}

void AVLTree::rotateLeft(Node*node) {
	Node*rightLeft = node->rchild->lchild;
	Node* right = node->rchild;
	if(node->parent!=NULL) {
		replaceChild(node->parent,node,right);
	}
	else {
		root = right;
		root->parent = NULL;
	}
	right->lchild = node;
	node->parent = right;
	node->rchild = rightLeft;
	if(rightLeft != NULL) {
		rightLeft->parent = node;
		updateHeight(rightLeft);
	}
	else {
		updateHeight(node);
	}
	
}
