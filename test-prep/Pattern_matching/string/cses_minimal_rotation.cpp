#include <bits/stdc++.h>

using namespace std;

int booth(const string &s) {
    int n = s.length();
    string S = s + s;
    vector<int> f(2 * n, -1);
    int k = 0; 
    
    for (int j = 1; j < 2 * n; j++) {
        char sj = S[j];
        int i = f[j - k - 1];
        
        while (i != -1 && sj != S[k + i + 1]) {
            if (sj < S[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        
        if (sj != S[k + i + 1]) { 
            if (sj < S[k]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    
    return k;
}

int main() {
    string s;

    cin >> s;
    
    int idx = booth(s);
    string min_rotation = s.substr(idx) + s.substr(0, idx);
    cout<<min_rotation<<endl;
    return 0;
}
