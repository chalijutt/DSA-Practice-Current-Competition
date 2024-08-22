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
int traverseForSum(node* root){
    if(root==NULL){
        return 0;
    }
    root->data=root->data+traverseForSum(root->left)+traverseForSum(root->right);
    return root->data;

}
void levelorderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* n=q.front();
        q.pop();
        if(n==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout<<n->data<<" ";
        if(n->left){
            q.push(n->left);
        }
        if(n->right){
            q.push(n->right);
        }
    }
}
int main(){
    node* root=buildTree();
    traverseForSum(root);
    levelorderTraversal(root);


    return 0;
}