#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* n=new node(d);
    n->left=buildTree();
    n->right=buildTree();
    return n;
}
class IEpair{
    public:
    int incSum;
    int excSum;
};
IEpair maxSum(node* root){
    IEpair p;
    if(root==NULL){
        p.excSum=0;
        p.incSum=0;
        return p;
    }
    IEpair Left=maxSum(root->left);
    IEpair Right=maxSum(root->right);
    int inc=root->data+Left.excSum+Right.excSum;
    int exc=max(Left.excSum,Left.incSum)+max(Right.excSum,Right.incSum);
    /*For Printing the subset that has maximum sum*/
    // if(inc>exc){
    //     cout<<root->data<<" ";
    // }
    p.incSum=inc;
    p.excSum=exc;

    return p;

}

int main(){
    node* root=buildTree();
    IEpair sum=maxSum(root);
    int MaxSum=max(sum.incSum,sum.excSum);
    cout<<endl;
    cout<<"Maximum Sum of Subset is "<<MaxSum<<endl;

    return 0;
}