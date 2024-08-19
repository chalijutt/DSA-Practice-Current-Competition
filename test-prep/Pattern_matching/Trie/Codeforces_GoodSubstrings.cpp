#include<bits/stdc++.h>
using namespace std;
// int good_substrings(string s,string maping,int allowed){
//     set<string> ds;
//     for(int i=0;i<s.length();i++){
//         string temp="";
//         int count=0;
//         for(int j=i;j<s.length();j++){
//             if(maping[s[j]-'a']=='0'){
//                 if(count<allowed){
//                     count++;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             temp+=s[j];
//             ds.insert(temp);
//         }
//     }
//     // for(auto y:ds){
//     //     cout<<y<<" ";
//     // }
//     // cout<<endl;
//     return ds.size();
// }
struct node{
    node* nxt[26];
    bool is_marked;
    node(){
        for(int i=0;i<26;i++) nxt[i]=NULL;
        is_marked=false;
    }
};
node* root;
int build_trie(string s, string maping,int allowed){
    root= new node();
    for(int i=0;i<s.length();i++){
        node* curr=root;
        for(int j=i;j<s.length();j++){
            int index=s[j]-'a';
            if(curr->nxt[index]==NULL){
                curr->nxt[index]= new node();
            }
            curr=curr->nxt[index];
        }
    }
    
    int count=0;
    for(int i=0;i<s.length();i++){
        node* curr=root;
        int bad=0;
        for(int j=i;j<s.length();j++){
            int index=s[j]-'a';
            
            if(maping[index]=='0'){
                bad++;
                
            }
                if(bad>allowed){
                break;
                }
            curr=curr->nxt[index];
            if(!curr->is_marked){
                    count++;
                    curr->is_marked=true;
            }
        }
    }
    
return count;
}
int main(){
    string s,mp;
    cin>>s>>mp;
    int allowed;
    cin>>allowed;
    
    cout<<build_trie(s,mp,allowed)<<endl;
    

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// struct TrieNode {
//     TrieNode* nxt[26];
//     bool is_marked;
//     TrieNode() {
//         for (int i = 0; i < 26; i++) {
//             nxt[i] = NULL;
//         }
//         is_marked = false;
//     }
// };

// TrieNode* root;

// int count_good_substrings(string s, string mapping, int allowed) {
//     root = new TrieNode();
//     int n = s.length();
//     int distinct_count = 0;

//     // Iterate over each starting position in the string
//     for (int i = 0; i < n; i++) {
//         TrieNode* curr = root;
//         int bad_count = 0;

//         // Build substrings starting from position i
//         for (int j = i; j < n; j++) {
//             int index = s[j] - 'a';

//             // Track bad characters
//             if (mapping[index] == '0') {
//                 bad_count++;
//             }

//             // If bad characters exceed the allowed limit, break
//             if (bad_count > allowed) {
//                 break;
//             }

//             // If the current node doesn't exist, create it
//             if (curr->nxt[index] == NULL) {
//                 curr->nxt[index] = new TrieNode();
//             }

//             curr = curr->nxt[index];

//             // If this node hasn't been marked before, it's a new distinct substring
//             if (!curr->is_marked) {
//                 curr->is_marked = true;
//                 distinct_count++;
//             }
//         }
//     }

//     return distinct_count;
// }

// int main() {
//     string s, mp;
//     cin >> s >> mp;
//     int allowed;
//     cin >> allowed;
//     cout << count_good_substrings(s, mp, allowed) << endl;

//     return 0;
// }
