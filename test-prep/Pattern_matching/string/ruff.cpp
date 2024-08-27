#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int> v={1,8};
auto it=upper_bound(v.begin(),v.end(),5);
int ind=distance(it,v.end())-1;
cout<<ind<<endl;
return 0;
}