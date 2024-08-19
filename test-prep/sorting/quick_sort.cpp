#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &v,int l,int r){
    int pivot=v[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return i+1;
}
void quick_sort(vector<int>& v, int l,int r){
    if(l<r){
        int p=partition(v,l,r);
        quick_sort(v,l,p-1);
        quick_sort(v,p+1,r);

        partition(v,l,r);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int l=0,r=n-1;
    quick_sort(v,l,r);
    for(auto y:v){
        cout<<y<<" ";
    }
    cout<<endl;
    return 0;
}