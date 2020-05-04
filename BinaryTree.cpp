// BinaryTree.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3314/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BinaryTree{
    public:
        
        Node *root;
        
        BinaryTree(){}

        struct Node* newnode(int value){
            struct Node *node = new Node();
            node->data = value;
            node->left = NULL;
            node->right = NULL;
            return node;
        }

        void add(int value){
            
        }
        
};