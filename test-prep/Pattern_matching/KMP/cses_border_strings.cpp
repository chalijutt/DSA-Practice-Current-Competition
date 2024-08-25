#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
// void count_border_string(const string& pattern) {
//    int count=0;
//    int i=0,j=pattern.length()-1;
//    while(j>0){
//     // cout<<"j="<<j<<endl;
//     if(pattern[j]==pattern[i]){
//         bool flag=true;
//         int temp=0;
//         for(j;j<pattern.length();){
//             temp++;
//             if(pattern[i]==pattern[j]){
//                 i++;
//                 j++;
//             }
//             else{
//                 i=0;
//                 j-=temp;
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag){
//             cout<<temp<<" ";
//             i=0;
//             j-=temp+1;
//         }
//     }
//     else{
//     j--;
//     if(j<=0){
//         break;
//     }

//     }
//    }
            
// }
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
    // count_border_string(s);
    // vector<int> ans=computeLPSArray(s);
    vector<int>lps=LPS(s);
    // for(auto y:lps){
    //     cout<<y<<" ";
    // }
    cout<<endl;
    int n=s.length();
    int length=lps[n-1];
    while (length>0)
    {
    
        arr[length]=1;
        length=lps[length-1];
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    
    
}