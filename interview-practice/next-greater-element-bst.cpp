/*
Given a BST node, return the node which has value just greater than the given node.

Example:

Given the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97
Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.

If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.

Assume that the value is always present in the tree.*/

#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

node* insertBST(node *root,int val)
{
	if(root==NULL)
	{
		return new node(val);
	}
	if(val<root->data)
	{
		root->left=insertBST(root->left,val);
	}
	else
	{
		root->right=insertBST(root->right,val);
	}
	return root;
}

//Approach1
node* nxtgreat(node* A,int B)
{
	node* tmp=A,*ans=NULL;
    while(tmp!=NULL){
        if(tmp->data<B){
            tmp=tmp->right;
        }
        else if(tmp->data==B){
            tmp=tmp->right;
        }
        else{
            if(ans==NULL || ans->data>tmp->data)
                ans=tmp;
            tmp=tmp->left;    
        }
    } 
    return ans;
}

//Approach2 -better
node* nxtgreat2(node* A,int B)
{
	int s=B+1;
	node* tmp=A,*mins=NULL;
	while(A!=NULL){
		if(A->data<s)
		 A=A->right;
		else if(A->data==s)
		 return A;
		else{
			mins=A;
			A=A->left;
		}
	}
	return mins;
}
int main()
{
	
	int arr[]={100,98,102,96,99,97},i;
	
	int k=	100;
	node* root=NULL;
	for(i=0;i<7;i++)
	{
		root=insertBST(root,arr[i]);
	}
	cout<<"\n";
	
	node* large=nxtgreat2(root,k);
	
	if(large==NULL)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	cout<<"next largest element is  "<<large->data<<"\n";
	
	
}