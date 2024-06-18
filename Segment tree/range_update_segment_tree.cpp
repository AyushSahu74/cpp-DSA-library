/*
Given an array of n integers, your task is to process q queries of the following types:
1) increase each value in range [a,b] by u
2) what is the value at position k?
*/

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    long long data;
    long long res;
    Node* left;
    Node* right;

    Node(long long value) 
    {
        data=value;
        res=0;
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

void update(int a,int b,int val,int l,int r,Node* n)
{
    if(a>r || b<l) return;
    if(a<=l && r<=b) 
    {
        n->res+=val;
        return;
    }
    int mid=(l+r)/2;
    update(a,b,val,l,mid,n->left);
    update(a,b,val,mid+1,r,n->right);
    return; 
}

long long query(int k,int l,int r,Node* n)
{
    if(n->res!=0)
    {
        n->data+=((r-l+1)*n->res);
        if(l!=r)
        {
            n->left->res+=n->res;
            n->right->res+=n->res;
        }
        n->res=0;
    }
    if(l==r) return n->data;
    int mid=(l+r)/2;
    if(k<=mid)
    {
        return query(k,l,mid,n->left);
    }
    else
    {
        return query(k,mid+1,r,n->right);
    }
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
update(a,b,val,l,r,head)
where, a,b is the starting and ending point on 0-indexed array on which we have to update value
       val is value to be updated at pos
       l=0, r=n-1

for getting value at position k
long long ans=query(k,l,r,head)
where, k isthe position of which we want value
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