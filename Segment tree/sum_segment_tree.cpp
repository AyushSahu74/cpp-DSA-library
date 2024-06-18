/*
Given an array of n integers, your task is to process q queries of the following types:
1) update the value at position k to u
2) what is the sum of values in range [a,b]?
*/

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    long long data;
    Node* left;
    Node* right;

    Node(long long value) 
    {
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

Node* createNode(long long value) {
  return new Node(value);
}

void build(Node* n,int l,int r,vector<int>&v)
{
    if(l==r)
    {
        n->data=v[l];
        return;
    }
    int mid=(l+r)/2;
    Node* lft=createNode(0);
    Node* rgt=createNode(0);
    n->left=lft;
    n->right=rgt;
    build(lft,l,mid,v);
    build(rgt,mid+1,r,v);
    n->data=n->left->data + n->right->data;
    return;
}

void update(int pos,int val,int l,int r,Node* n)
{
    if(l==r && l==pos) 
    {
        n->data=val;
        return;
    }
    if(r<pos || l>pos) return;

    int mid=(l+r)/2;
    update(pos,val,l,mid,n->left);
    update(pos,val,mid+1,r,n->right);
    n->data=n->left->data + n->right->data;
    return;
}

long long query(int a,int b,int l,int r,Node* n)
{
    if(l>b || r<a) return 0;
    if(l>=a && r<=b) return n->data;
    int mid=(l+r)/2;
    return query(a,b,l,mid,n->left)+query(a,b,mid+1,r,n->right);
}
/*
Start by creating a root node of tree
Node* head=createNode(0);

for building segment tree
build(head,l,r,v);
where, head is root node
       l=0 r=n-1 (n is number of values in array v)
       v is the array on which we have to run queries

for updating segment tree
update(pos,val,l,r,head)
where, pos is the position on 0-indexed array on which we have to update value
       val is value to be updated at pos
       l=0, r=n-1

for getting sum
long long sum=query(a,b,l,r,head)
where, a,b are starting and ending point respectively in 0-indexed array, we want sum from a to b(inclusive)
*/
int main()
{
    // int n;
    // cin>>n;
    // vector<int>v(n);
    // for(int i=0;i<n;i++) cin>>v[i];
    // Node* head=createNode(0);
    // build(head,0,n-1,v);
    return 0;
}