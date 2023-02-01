// anticlockwise boundary traversal

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

void leafNodes(Node*root,vector<int>&res){
    if(!root)
     return;
    leafNodes(root->left,res);

    if(!root->right and !root->left){
        res.push_back(root->data);        
    }

    leafNodes(root->right,res);

}

vector<int> boundtrav(Node *root){

    if(!root)
     return {};

    vector<int> res={};

    // root
    
    res.push_back(root->data);

    if(!root->left and !root->right)
     return res;
    


    // left boundary

    Node *tmp=root->left;
       

    while(tmp and !(!tmp->right and !tmp->left)){
        res.push_back(tmp->data);
        if(tmp->left){
            tmp=tmp->left;
        }
        else if (tmp->right){
            tmp=tmp->right;
        }
    }

    
    // leaf nodes

    leafNodes(root,res);

    // right boundary reversed

    tmp=root->right;
    vector<int>rightb={};

    while(tmp and !(!tmp->right and !tmp->left)){
        rightb.push_back(tmp->data);

        if(tmp->right){
            tmp=tmp->right;
        }
        else if(tmp->left){
            tmp=tmp->left;
        }
    }

    // insert the reversed right traversal

    res.insert(res.end(),rightb.rbegin(),rightb.rend());
    return res;
}

int main(){
  struct Node * root = new Node(1);
  root -> left = new Node(2);
  root -> left -> left = new Node(3);
  root -> left -> left -> right = new Node(4);
  root -> left -> left -> right -> left = new Node(5);
  root -> left -> left -> right -> right = new Node(6);
  root -> right = new Node(7);

  vector<int> res=boundtrav(root);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

}