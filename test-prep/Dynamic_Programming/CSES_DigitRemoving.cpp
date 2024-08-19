#include<bits/stdc++.h>
using namespace std;
int digit_removal(int n){
    int count=0;
    while(n){
        int temp=n,m=-1;
        while(temp){
            int d=temp%10;
            temp=temp/10;
            m=max(m,d);
        }
        // cout<<"max_digit>="<<m<<" "<<"n==>"<<n<<endl;
        n-=m;
        count++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<digit_removal(n)<<endl;

    return 0;
}