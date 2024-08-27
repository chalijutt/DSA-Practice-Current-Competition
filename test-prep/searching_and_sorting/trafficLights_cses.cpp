// #include<bits/stdc++.h>
// using namespace std;
// void solve(vector<int>&v,int street,int lights){
//     vector
   
// }
// int main(){
//     int x,n;
//     cin>>x>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     solve(v,x,n);


//     return 0;
// }
#include <iostream>
#include <vector>
#include <set>

class SegmentTree {
private:
    std::vector<int> tree;
    int size;
    
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = std::max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return std::max(query(2 * node + 1, start, mid, l, r), query(2 * node + 2, mid + 1, end, l, r));
    }
    
public:
    SegmentTree(int n) : size(n) {
        tree.resize(4 * n, 0);
    }
    
    void update(int idx, int value) {
        update(0, 0, size - 1, idx, value);
    }
    
    int query(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }
};

int main() {
    int X, N;
    std::cin >> X >> N;
    
    std::set<int> marks;
    marks.insert(0);
    marks.insert(X);
    
    SegmentTree segTree(X + 1);
    for (int i = 0; i <= X; ++i) {
        segTree.update(i, i);
    }
    
    int lastMark = 0;
    
    for (int i = 0; i < N; ++i) {
        int pos;
        std::cin >> pos;
        
        marks.insert(pos);
        
        auto it = marks.find(pos);
        auto prev = std::prev(it);
        auto next = std::next(it);
        
        int prevMark = *prev;
        int nextMark = *next;
        
        // Remove the old segment length
        segTree.update(prevMark, nextMark - prevMark);
        
        // Update the new segments
        segTree.update(prevMark, pos - prevMark);
        segTree.update(pos, nextMark - pos);
        
        // Query for the maximum unmarked segment length
        std::cout << segTree.query(0, X) << std::endl;
    }
    
    return 0;
}
