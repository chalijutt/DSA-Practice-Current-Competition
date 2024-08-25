#include<bits/stdc++.h>
using namespace std;
// int palindrome_len(string s,int l,int r){
//     int n=s.length();
//     int count=0;
//     while((l>=0 )&& (r<n) && (s[l]==s[r])){
//         l--;
//         r++;
//         count++;
//     }
//     if(count){
//     return r-l-1;

//     }
//     return 0;
// }
// void longest_palindrome(string s){
//     int start=0,end=0;
//     for(int i=0;i<s.length();i++){
//         int len1=palindrome_len(s,i,i);
//         int len2=palindrome_len(s,i,i+1);
//         int len=max(len1,len2);
//         // cout<<"len="<<len<<endl;
//         if(len>=end-start+1){
//             start=i-((len-1)/2);
//             end=i+(len/2);
//         }
//     }
//     // cout<<"start="<<start<<","<<"end="<<end<<endl;
//     cout<<s.substr(start,end-start+1)<<endl;
// }
// void longest_palendrome_opt(string s){
//     int n=s.length();
//     vector<int> continuous(n,0);
//     vector<int> palendrome_len(n,0);
//     continuous[n-1]=1;
//     palendrome_len[n-1]=1;
//     for(int i=n-2;i>=0;i--){
//         if(s[i]==s[i+1]){
//             continuous[i]=continuous[i+1]+1;
//         }
//         else{
//             continuous[i]=1;
//         }
//     }
//     int max_count=1,max_index=n-1;
//     for(int i=n-2;i>=0;i--){
        
//         palendrome_len[i]=continuous[i];
        
//         if(max_count<palendrome_len[i]){
//             max_index=i;
//             max_count=palendrome_len[i];
//         }
//         int j=i+palendrome_len[i+1]+1;
//         if(j<n){
//             if(s[j]==s[i]){
//                 palendrome_len[i]=max(palendrome_len[i],palendrome_len[i+1]+2);
//             }
//         }
//         if(max_count<palendrome_len[i]){
//             max_index=i;
//             max_count=palendrome_len[i];
//         }
        
//     }
//     for(auto y:continuous){
//         cout<<y<<" ";
//     }
//     cout<<endl;
//     for(auto y:palendrome_len){
//         cout<<y<<" ";
//     }
//     cout<<endl;
//     cout<<s.substr(max_index,palendrome_len[max_index])<<endl;
// }
void manacher_algo(string s){
    int c=0,r=0,n=s.length(),max_curr=0,max_index=-1;
    vector<int> lps(n,0); 

    for(int i=1;i<n;i++){
        int mirror=c-(i-c);
        if(mirror<r){
            lps[i]=min(lps[mirror],r-i);
        }
        while(s[i+lps[i]+1]==s[i-lps[i]-1]){
            lps[i]++;
        }
        if(lps[i]>max_curr){
            max_curr=lps[i];
            max_index=i;
        }
        if(i+lps[i]>r){
            c=i;
            r=i+lps[i];
        }
    }
    for(int i=max_index-lps[max_index];i<=max_index+lps[max_index];i++){
        if(s[i]!='#'){
            cout<<s[i];
        }
    }
    cout<<endl;
    // for(auto y:s){
    //     cout<<y<<" ";
    // }
    // cout<<endl;
    // for(auto y:lps){
    //     cout<<y<<" ";
    // }
    // cout<<endl;
    // cout<<"c="<<c<<",value="<<lps[c]<<endl;
}
int main(){
    string s;
    cin>>s;
    // longest_palendrome_opt(s);
    string new_s="?";
    for(int i=0;i<s.length();i++){
        string temp="#";
        temp+=s[i];
        new_s+=temp;
    }
    new_s+="#!";
    manacher_algo(new_s);

    return 0;
}