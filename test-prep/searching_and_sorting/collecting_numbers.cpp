#include<bits/stdc++.h>
using namespace std;
int arr[200001];
void solve(vector<int>&v){
    long long int smallest=1,count=1,last_index=arr[smallest];
    int i=0;
    int temp=smallest+1;
    while(smallest<=v.size()){
        if(arr[temp] && arr[temp]>last_index){
            last_index=arr[temp];
            temp+=1;
            cout<<"temp="<<temp<<",last_index="<<last_index<<endl;
        }
        else{
            smallest=temp;
            last_index=arr[smallest];
            temp=smallest+1;
            cout<<"temp="<<temp<<",last_index="<<last_index<<"smallest="<<smallest<<endl;
            if(smallest<=v.size()){
            count++;

            }
        }
        
    }
    cout<<count<<endl;
}
int main(){
    // #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    // #endif
    int n;
    cin>>n;
    memset(arr,0,sizeof(arr));
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        arr[v[i]]=i;
    }
    
    solve(v);


    return 0;
}
