#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int>& v, int n){
    for(int i=1;i<n;i++){
        int current=v[i];
        int j=i-1;
        while(v[j]>current && j>=0){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=current;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    insertion_sort(v,n);
    for(auto y:v){
        cout<<y<<endl;
    }
    return 0;
}