// #include<bits/stdc++.h>
// using namespace std;
// void money_sums(vector<int>& v,set<int> &s,int sum,int index){
//    if(index==v.size()){
//     s.insert(sum);
//     return;
//    }
//    money_sums(v,s,sum+v[index],index+1);
//    money_sums(v,s,sum,index+1);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//      set<int> s;
//     money_sums(v,s,0,0);
//     s.erase(0);
//     cout<<s.size()<<endl;
//     for(auto y=s.begin();y!=s.end();y++){
//         if(*y!=0)
//         cout<<*y<<" ";
//     }
//     cout<<endl;

//     return 0;
// }
// #include <bits/stdc++.h>

// // We define a key type for memoization
// using MemoKey = std::pair<int, int>;
// using Memo = std::map<MemoKey, bool>; // or use std::unordered_map
// using namespace std;
// void money_sums(std::vector<int>& v, std::set<int>& s, int sum, int index, Memo& memo) {
//     // Check if this state has already been computed
//     MemoKey key = {sum, index};
//     if (memo.find(key) != memo.end()) {
//         return;
//     }

//     // Base case: If we've considered all elements
//     if (index == v.size()) {
//         s.insert(sum);
//         return;
//     }

//     // Include the current element
//     money_sums(v, s, sum + v[index], index + 1, memo);

//     // Exclude the current element
//     money_sums(v, s, sum, index + 1, memo);

//     // Mark this state as computed
//     memo[key] = true;
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//      set<int> s;
//     Memo memo; // Memoization table

//     money_sums(v, s, 0, 0, memo);
// s.erase(0);
// cout<<s.size()<<endl;
//     // for (int sum : s) {
//     //     std::cout << sum << " ";
//     // }

//     return 0;
// }
#include <bits/stdc++.h>
// For accumulate
using namespace std;
void money_sums(std::vector<int>& v, std::set<int>& s, int sum, int index, std::vector<std::vector<bool>>& memo) {
    // If this state has already been computed, return
    if (memo[index][sum]) {
        return;
    }

    // Mark this state as computed
    memo[index][sum] = true;

    // Base case: If we've considered all elements
    if (index == v.size()) {
        s.insert(sum);
        return;
    }

    // Include the current element in the sum
    money_sums(v, s, sum + v[index], index + 1, memo);

    // Exclude the current element from the sum
    money_sums(v, s, sum, index + 1, memo);
}

int main() {
       int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
     set<int> s;

    // Calculate the maximum possible sum
    int max_sum = accumulate(v.begin(), v.end(), 0);

    // Create a 2D array for memoization
    // We need size (v.size() + 1) x (max_sum + 1) to account for all indices and sums
    std::vector<std::vector<bool>> memo(v.size() + 1, std::vector<bool>(max_sum + 1, false));

    money_sums(v, s, 0, 0, memo);
    s.erase(0);
    std::cout << s.size()<<endl;
    for (int sum : s) {
        std::cout << sum << " ";
    }

    return 0;
}


// #include <bits/stdc++.h> // For accumulate
// using namespace std;
// void money_sums(const std::vector<int>& v, std::set<int>& s) {
//     int max_sum = accumulate(v.begin(), v.end(), 0);
//     std::vector<bool> dp(max_sum + 1, false);
//     dp[0] = true;  // Sum of 0 is always possible (by choosing no elements)

//     for (int num : v) {
//         for (int j = max_sum; j >= num; --j) {
//             if (dp[j - num]) {
//                 dp[j] = true;
//             }
//         }
//     }

//     for (int i = 1; i <= max_sum; ++i) {
//         if (dp[i]) {
//             s.insert(i);
//         }
//     }
// }

// int main() {
//       int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//      set<int> s;

//     money_sums(v, s);
//     s.erase(0);
//     std::cout << s.size() << std::endl;
//     for (int sum : s) {
//         std::cout << sum << " ";
//     }

//     return 0;
// }
