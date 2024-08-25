#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&v){
    long long int smallest_sum=1;
    sort(v.begin(),v.end());
    int i=0;
    
    while(i< v.size() && smallest_sum>=v[i]){
        smallest_sum+=v[i];
        i++;
    }
    // cout<<"sum="<<smallest_sum+v[i]<<endl;
    cout<<smallest_sum<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve(v);

    return 0;
}