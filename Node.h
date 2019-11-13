
#ifndef NODE_h
#define NODE_h

#include <string>

struct Node {
    int height;
    std::string str;
    Node* lchild = NULL;
    Node* rchild = NULL;
    Node* parent = NULL;
    Node(const std::string&);
};

#endif
