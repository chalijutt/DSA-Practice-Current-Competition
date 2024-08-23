#include<bits/stdc++.h>
const int MOD = 1000000007;
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
};

int main() {
    std::string s;
    int k;

    // Read input
    std::cin >> s >> k;
    Trie trie= Trie();
    for (int i = 0; i < k; ++i) {
        std::string word;
        std::cin >> word;
        trie.insert(word);
    }
    int n = s.length();
    std::vector<long long> dp(n + 1, 0LL);
    dp[n] = 1LL;  // Base case: empty string

    // Fill dp array using Trie to check for matching suffixes
    for (int i = n-1; i >=0; i--) {
        node* curr=trie.root;int ans=0;
        for (int j = i; j <n; j++) {
            if(curr->nxt[s[j]-'a']==NULL){
                break;
            }
            curr=curr->nxt[s[j]-'a'];
            if(curr->is_end){
                ans=(ans+dp[j+1])%MOD;
            }
        }
        dp[i]=ans;
    }
    // Output the result
    std::cout << dp[0] << std::endl;
    return 0;
}
