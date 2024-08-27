// #include<bits/stdc++.h>
// using namespace std;
// int arr[200001];
// void solve(vector<int>&v){
//     long long int smallest=1,count=1,last_index=arr[smallest];
//     int i=0;
//     int temp=smallest+1;
//     while(smallest<=v.size()){
//         if(arr[temp] && arr[temp]>last_index){
//             last_index=arr[temp];
//             temp+=1;
//         }
//         else{
//             smallest=temp;
//             last_index=arr[smallest];
//             temp=smallest+1;
//             if(smallest<=v.size()){
//             count++;

//             }
//         }
        
//     }
//     cout<<count<<endl;
// }
// int main(){
//     #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
//     #endif
//     int n,s;
//     cin>>n>>s;
//     memset(arr,0,sizeof(arr));
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//         arr[v[i]]=i;
//     }
//     while(s--){
//         int a,b;
//         cin>>a>>b;
//         a--;
//         b--;
//         swap(arr[v[a]],arr[v[b]]);
//         swap(v[a],v[b]);
//         solve(v);

//     }

//     return 0;
// }
