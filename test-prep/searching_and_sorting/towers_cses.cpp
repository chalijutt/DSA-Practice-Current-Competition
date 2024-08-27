#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&v){
    int n=v.size();
    vector<int> towers;
    for(int i=0;i<n;i++){
        if(towers.size()==0){
            towers.push_back(v[i]);
        }
        else{
            auto it=upper_bound(towers.begin(),towers.end(),v[i]);
            int ind=distance(towers.begin(),it);
            if(ind<towers.size()){

            towers[ind]=v[i];
            }
            else{
                // cout<<"cube="<<v[i]<<endl;

                towers.push_back(v[i]);
            }
        }
    }
    cout<<towers.size()<<endl;
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
