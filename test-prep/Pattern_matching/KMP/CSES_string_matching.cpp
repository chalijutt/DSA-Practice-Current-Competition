// #include<bits/stdc++.h>
// using namespace std;

// const int p = 31, mod = 1e9 + 7;

// int poly_hash(string s) {
// 	int hash = 0;
// 	int p_power = 1;

// 	for (int i = 0; i < s.size(); i++) {
// 		hash += (s[i] - 'a' + 1) * p_power;
// 		p_power *= p;

// 		hash %= mod;
// 		p_power %= mod;
// 	}

// 	return hash;
// }

// int powr(int a, int b) {
// 	// (a^b)%mod
// 	int res = 1;
// 	while (b) {
// 		if (b & 1) res *= a;
// 		b /= 2;
// 		a *= a;

// 		a %= mod;
// 		res %= mod;
// 	}
// 	return res;
// }

// int inv(int x) {
// 	return powr(x, mod - 2);
// }

// int main() {

// 	string text;
// 	string pattern;
//     cin>>text;
//     cin>>pattern;

// 	int pat_hash = poly_hash(pattern);

// 	int n = text.size(), m = pattern.size();

// 	int text_hash = poly_hash(text.substr(0, m));

//     long long int count=0;
// 	if (pat_hash == text_hash) {
// 		count++;
        
// 	}

// 	for (int i = 1; i + m <= n; i++) {
        
// 		// remove last character
// 		text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod) % mod;

// 		text_hash = (text_hash * inv(p)) % mod;

// 		text_hash = (text_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;

// 		// cout << pat_hash << " " << text_hash << '\n';

// 		if (text_hash == pat_hash) {
// 			// cout << i << '\n';
//             count=(count+1)%mod;
// 		}
        
// 	}


//     cout<<count<<endl;

// 	return 0;
// }
// int rabinKarp(const std::string& text, const std::string& pattern) {
//     int n = text.length();
//     int m = pattern.length();
//     int patternHash = 0, textHash = 0, h = 1;
//     int base = 256;
//     int mod = 101;  // A prime number to use in the hash function
//     int count = 0;

//     // Precompute h = pow(base, m-1) % mod
//     for (int i = 0; i < m - 1; i++) {
//         h = (h * base) % mod;
//     }

//     // Compute the hash of the pattern and the first window of text
//     for (int i = 0; i < m; i++) {
//         patternHash = (base * patternHash + pattern[i]) % mod;
//         textHash = (base * textHash + text[i]) % mod;
//     }

//     // Slide the pattern over text one character at a time
//     for (int i = 0; i <= n - m; i++) {
//         // Check if the hash values are the same
//         if (patternHash == textHash) {
//             // If the hash values match, check the actual strings
//             if (text.substr(i, m) == pattern) {
//                 count++;
//             }
//         }

//         // Calculate hash of the next window of text: Remove leading digit, add trailing digit
//         if (i < n - m) {
//             textHash = (base * (textHash - text[i] * h) + text[i + m]) % mod;

//             // We might get a negative value of textHash, convert it to positive
//             if (textHash < 0) {
//                 textHash += mod;
//             }
//         }
//     }

//     return count;
// }

// int main() {
//     std::string text ;
//     std::string pattern ;
//     std::cin>>text>>pattern;
//     std::cout << rabinKarp(text, pattern) << std::endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
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

// KMP Search function
int KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPSArray(pattern);
    int i = 0; // index for text[]
    int j = 0; // index for pattern[]
    int count = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return count;
}

int main() {
    string text ;
    string pattern;
    cin>>text>>pattern;
    cout << KMPSearch(text, pattern) << endl;
    return 0;
}
