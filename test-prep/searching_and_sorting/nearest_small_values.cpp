#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&v){
    vector<int> answer(v.size(),0);
    answer[0]=0;
    for(int i=1;i<v.size();i++){
        if(answer[i-1]==0){
            if(v[i-1]<v[i]){
                answer[i]=i;
            }
            continue;
        }
        for(int j=i-1;j>=0;){
            int ind=answer[j];
            if(v[j]<v[i]){
                answer[i]=j+1;
                break;
            }
            else{
                if(ind && v[ind-1]<v[i]){
                    answer[i]=ind;
                     break;
                }
                if(ind==0){
                    break;
                }
                
            }
            j=answer[ind-1]-1;
        }
    }

   for(auto y:answer){
    cout<<y<<" ";
   }
   cout<<endl;
}
int main(){
    int x,n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve(v);


    return 0;
}
