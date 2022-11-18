#include <bits/stdc++.h> 
using namespace std;
/*************************************************************

    Following is the Binary Tree node structure*/

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

/**************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int p=-1,s=-1;
    BinaryTreeNode<int>* troot=root;
    //predecessor is the max of left subtree nodes
    while(root!=NULL){
        if(key<=root->data){
            root=root->left;
        }
        else{
            p=root->data;
            root=root->right;
        }
    }
    
    // successor is the minimum of right subtree nodes

    
    while(troot!=NULL){
        if(key>=troot->data){
            troot=troot->right;
        }
        else{
            s=troot->data;
            troot=troot->left;
        }
    }
    
        return {p,s};

}
