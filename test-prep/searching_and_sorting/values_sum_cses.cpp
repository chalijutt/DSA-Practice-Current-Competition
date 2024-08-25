#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &v,int target,unordered_map<int,int> &ump){
    
    bool flag=false;
    for(int i=0;i<v.size();i++){
        int r=target-v[i];
        if(r<0){
            continue;
        }
        if(ump.find(r)!=ump.end()){
            if(i!=ump[r]){

            cout<<i+1<<" "<<ump[r]+1<<endl;
            flag=true;
            break;
            }
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    int smallest=INT_MAX;
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++){
        cin>>v[i];
        ump[v[i]]=i;
        smallest=min(smallest,v[i]);
    }
    if(smallest>=t or t==1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{

    solve(v,t,ump);
    }

    return 0;
}