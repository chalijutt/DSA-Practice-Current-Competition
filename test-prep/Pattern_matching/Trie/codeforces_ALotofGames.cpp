// #include<bits/stdc++.h>
// using namespace std;
// struct node{
//     node* nxt[26];
//     node(){
//         for(int i=0;i<26;i++) nxt[i]=NULL;
//     }
// };
// node* root;
// vector<char> allowed_characters(26,0);
// void build_trie(vector<string> s){
//     for(int i=0;i<s.size();i++){
//         node* curr=root;
//         for(int j=0;j<s[i].length();j++){
//             int ind=s[i][j]-'a';
//             allowed_characters[ind]=1;
//             if(curr->nxt[ind]==NULL){
//                 curr->nxt[ind]=new node();
//             }
//             curr=curr->nxt[ind];
//         }

//     }
// }
// bool search_trie(string s){
//     node* curr=root;
//     for(int j=0;j<s.length();j++){
//         int ind=s[j]-'a';
//         if(curr->nxt[ind]==NULL){
//             return false;
//         }
//         curr=curr->nxt[ind];
//     }
//     return true;
// }
// void solve(int k){
//     string current_player="First";
//     string word="",last_winner="First";
//     for(int i=0;i<k;i++){
//         for(int j=0;j<26;j++){
//             if(allowed_characters[j]){
//                 bool flag=search_trie(word+char(j+97));
//                 if(flag){
//                     if(current_player=="First"){
//                         last_winner="First";
//                         current_player="Second";
//                     }
//                     else{
//                         last_winner="Second";
//                         current_player="First";
//                     }
//                     break;
//                 }
//             }
//         }
//     }
//     cout<<last_winner<<endl;
// }
// int main(){
//     root=new node();
//     int n,k;
//     cin>>n>>k;
//     vector<string> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     build_trie(v);
//     solve(k);
//     return 0;
// }
#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define FORN(i,s,n) for(int i=s;i<(int)(n);i++)
#define FOR(i,n) FORN(i,0,n)
#define FORIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int64,int64> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

int main(){
    vector < pair<char, int> > trie[100010];
    int N,M; cin>>N>>M;
    string s;
    int ul=1;
    FOR(i,N){
        int act=0;
        cin>>s;
        FOR(j,sz(s)){
            cout<<"act="<<act<<endl;
            cout<<"ul="<<ul<<endl;
            bool f2=0;
            FOR( k,sz(trie[act]) ){
                if( trie[act][k].fst==s[j] ) {act=trie[act][k].snd; f2=1; break;}
            }
            if(f2) continue;
            trie[act].pb( mp( s[j], ul ) );
            ul++;
            act=ul-1;
        }
    }
    cout<<"ul="<<ul<<endl;
    // vector < int > G(100010,-1);
    // for( int i=ul-1;i>=0;i-- ){
    //     if ( trie[i].size()==0 ) {G[i]=0; continue;}
    //     set <int> S;
    //     FOR(j, sz(trie[i]) ) S.insert( G[trie[i][j].snd] );
    //     int  cont=0;
    //     bool f=1;
    //     for ( set<int>::iterator it=S.begin(); it!=S.end();it++ ){
    //         if( *it!=cont ) {G[i]=cont;f=0;break;}
    //         cont++;
    //     }
    //     if(f) G[i]=cont;
    // }
    // if(G[0]) {

    //     for( int i=ul-1;i>=0;i-- ){
    //         if ( trie[i].size()==0 ) {G[i]=1; continue;}
    //         set <int> S;
    //         FOR(j, sz(trie[i]) ) S.insert( G[trie[i][j].snd] );
    //         int  cont=0;
    //         bool f=1;
    //         for ( set<int>::iterator it=S.begin(); it!=S.end();it++ ){
    //             if( *it!=cont ) {G[i]=cont;f=0;break;}
    //             cont++;
    //         }
    //         if(f) G[i]=cont;
    //     }
    //     if( G[0]==0 ){
    //         if( M%2==0 ) cout<<"Second"<<endl;
    //         else cout<<"First"<<endl;
    //     }
    //     else{
    //         cout<<"First"<<endl;
    //     }

    // }
    // else cout<<"Second"<<endl;
}