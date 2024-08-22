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
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int D1=height(root->left)+height(root->right);
    int D2=diameter(root->left);
    int D3=diameter(root->right);
    return max(D1,max(D2,D3));

}
int main(){
    node* root=buildTree();
    // cout<<"diameter="<<diameter(root)<<endl;
    cout<<"height="<<height(root)<<endl;



    return 0;
}