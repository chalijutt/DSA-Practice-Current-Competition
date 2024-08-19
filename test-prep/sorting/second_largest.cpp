#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int m=v[0];
    for(int i=0;i<n;i++){
        m=max(m,v[i]);
    }
    int s_max=m*-1;
    for(int i=0;i<n;i++){
        if(v[i]==m){
            continue;
        }
        if(v[i]>=s_max){
            s_max=v[i];
        }
    }
    cout<<"second_largest element is :"<<" "<<s_max<<endl;
    return 0;
}