#include<bits/stdc++.h>
using namespace std;
struct node{
    node* nxt[26];
    bool is_end;
    node(){
    for(int i=0;i<26;i++) nxt[i]=NULL;
    is_end=false;
    }
};
class Trie {
public:
node* root;
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* curr=root;
        for(int i=0;i<word.length();i++){
        int index=word[i]-'a';
        if(curr->nxt[index]==NULL){
            curr->nxt[index]=new node();
        }
        curr=curr->nxt[index];

        }
        curr->is_end=true;
    }
    
    bool search(string word) {
        node* curr=root;
        for(int i=0;i<word.length();i++){
        int index=word[i]-'a';
        if(curr->nxt[index]==NULL){
            cout<<"searching="<<word[i]<<endl;
            return false;
        }
        curr=curr->nxt[index];

        }
        if(curr->is_end){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        node* curr=root;
        for(int i=0;i<prefix.length();i++){
        int index=prefix[i]-'a';
        if(curr->nxt[index]==NULL){
            return false;
        }
        curr=curr->nxt[index];

        }
        return true;
    }
};

int main(){
   Trie* obj = new Trie();
   while(true){
    string word,prefix;
    string operation;
    cin>>operation;
    if(operation=="insert"){
        cin>>word;
    obj->insert(word);

    }
    if(operation=="search"){
        cin>>word;
    bool param_2 = obj->search(word);
    cout<<param_2<<endl;
    }
    if(operation=="startsWith"){
        cin>>prefix;
    bool param_3 = obj->startsWith(prefix);
    cout<<param_3<<endl;
    }

   }
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */