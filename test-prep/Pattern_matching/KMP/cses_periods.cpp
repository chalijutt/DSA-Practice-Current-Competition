#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
vector<int> LPS(string s){
    int n=s.length();
    vector<int> lps(n,0);
    lps[0]=0;
    int i=1,length=0;
    while(i<n){
        if(s[i]==s[length]){
            length++;
            lps[i]=length;
            i++;
        }
        else{
            if(length){
                length=lps[length-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
int main(){
    string s;
    cin>>s;
    memset(arr,0,sizeof(arr));
    int n=s.length();
    vector<int> lps=LPS(s);
    // for(auto y:lps){
    //     cout<<y<<" ";
    // }
    // cout<<endl;
    int length=lps[n-1];
    while(length>0){
        arr[n-length]=1;
        length=lps[length-1];
    }
    arr[n]=1;
    for(int i=0;i<=n;i++){
        if(arr[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    
    return 0;
}