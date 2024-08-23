#include<bits/stdc++.h>
using namespace std;
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m);
    int length = 0;
    lps[0] = 0; // LPS[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}
int main(){
    string s;
    cin>>s;
    vector<int> ans=computeLPSArray(s);
    for(auto y:ans){
        cout<<y<<" ";
    }
    cout<<endl;
}