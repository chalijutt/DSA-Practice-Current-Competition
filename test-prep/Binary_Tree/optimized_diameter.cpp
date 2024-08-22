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
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);

}
class HDpair{
    public:
    int height;
    int diameter;
};
HDpair diameter(node* root){
    HDpair p;
    if(root==NULL){
        p.height=0;
        p.diameter=0;
        return p;
    }
    HDpair left=diameter(root->left);
    HDpair right=diameter(root->right);
    int D1=1+max(left.height,right.height);
    int D2=left.diameter;
    int D3=right.diameter;
    p.height=D1;
    p.diameter=max(D1,max(D2,D3));
    return p;
    
}
int main(){
    node* root=buildTree();
    cout<<"diameter="<<diameter(root).diameter<<endl;




    return 0;
}