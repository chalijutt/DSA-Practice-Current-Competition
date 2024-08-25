#include<bits/stdc++.h>
using namespace std;
long long int solve(vector<int> &v){
    sort(v.begin(),v.end());
    int median=median=v[(v.size())/2];
    long long int ans=0;
    for(int i=0;i<v.size();i++){
        ans+=abs(median-v[i]);
    }
    return ans;

    
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<solve(v)<<endl;


    return 0;
}