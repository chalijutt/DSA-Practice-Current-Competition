#include<iostream>
#include<vector>
using namespace std;
void merging(vector<int> &v,int l,int mid,int r){
    vector<int> v1,v2;
    for(int i=l;i<=mid;i++){
        v1.push_back(v[i]);
    }
    for(int i=mid+1;i<=r;i++){
        v2.push_back(v[i]);
    }
    // for(auto y:v1){
    //     cout<<y<<" ";
    // }
    // cout<<endl;
    // for(auto y:v2){
    //     cout<<y<<" ";
    // }
    // cout<<endl;
    int len1=v1.size(),len2=v2.size();
    int i=0,j=0,index=l;

    while(i< len1 && j<len2){
 
        if(v1[i]<=v2[j]){
            v[index]=v1[i];
            i++;
            index++;
        }
        else{
            v[index]=v2[j];
            j++;
            index++;
        }
    }
    while(i<len1){
        v[index]=v1[i];
        index++;
        i++;
    }
    while(j<len2){
        v[index]=v2[j];
        index++;
        j++;
    }
   
}
void merge_sort(vector<int>& v, int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(v,l,mid);
        merge_sort(v,mid+1,r);

        merging(v,l,mid,r);
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
    merge_sort(v,l,r);
    for(auto y:v){
        cout<<y<<" ";
    }
    cout<<endl;
    return 0;
}