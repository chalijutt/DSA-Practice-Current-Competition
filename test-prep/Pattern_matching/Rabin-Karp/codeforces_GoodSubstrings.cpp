#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;  // A large prime modulus
const int P = 31;  // Base for hashing

// Function to compute the rolling hash of substrings
long long compute_hash(const string &s, int l, int r, const vector<long long> &pows, const vector<long long> &hashes) {
    long long hash_val = (hashes[r + 1] - (hashes[l] * pows[r - l + 1]) % MOD + MOD) % MOD;
    return hash_val;
}

// Main function to count distinct good substrings
int count_distinct_good_substrings(const string &s, const string &mapping, int allowed) {
    int n = s.length();
    vector<long long> pows(n + 1, 1);
    vector<long long> hashes(n + 1, 0);
    
    // Compute powers of P and prefix hashes
    for (int i = 0; i < n; i++) {
        pows[i + 1] = (pows[i] * P) % MOD;
        hashes[i + 1] = (hashes[i] * P + (s[i] - 'a' + 1)) % MOD;
    }
    
    set<long long> seen_hashes;
    int count = 0;
    
    // Check substrings of all possible lengths
    for (int len = 1; len <= n; len++) {
        unordered_map<long long, bool> good_hashes;
        for (int i = 0; i <= n - len; i++) {
            int end = i + len - 1;
            int bad_count = 0;
            
            // Count bad characters in the current substring
            for (int j = i; j <= end; j++) {
                if (mapping[s[j] - 'a'] == '0') {
                    bad_count++;
                }
            }
            
            if (bad_count <= allowed) {
                long long hash_val = compute_hash(s, i, end, pows, hashes);
                if (good_hashes.find(hash_val) == good_hashes.end()) {
                    good_hashes[hash_val] = true;
                    seen_hashes.insert(hash_val);
                }
            }
        }
    }
    
    return seen_hashes.size();
}

int main() {
    string s, mapping;
    cin >> s >> mapping;
    int allowed;
    cin >> allowed;

    cout << count_distinct_good_substrings(s, mapping, allowed) << endl;

    return 0;
}
