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
class BHpair{
    public:
    int height;
    bool balanced;
};
BHpair isBalanced(node* root){
    BHpair p;
    if(root==NULL){
        p.balanced=true;
        p.height=0;
        return p;
    }
    BHpair lb=isBalanced(root->left);
    BHpair rb=isBalanced(root->right);
    if((lb.balanced) and (rb.balanced) and (abs(lb.height-rb.height)<=1)){
        p.balanced=true;
    }
    else{
        p.balanced=false;
    }
    p.height=1+max(lb.height,rb.height);
    return p;

}

int main(){
    node* root=buildTree();
    bool isbalanced=isBalanced(root).balanced;
    if(isbalanced){
    cout<<"Tree is Balanced"<<endl;

    }
    else{
        cout<<"Tree is not balanced"<<endl;
    }



    return 0;
}