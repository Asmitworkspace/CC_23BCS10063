#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); 
        build(arr, 0, n - 1, 1);
    }

    void build(vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, start, mid, 2 * node);
        build(arr, mid + 1, end, 2 * node + 1);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int l, int r) {
        return queryUtil(0, n - 1, l, r, 1);
    }

    int queryUtil(int start, int end, int l, int r, int node) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int leftAns = queryUtil(start, mid, l, r, 2 * node);
        int rightAns = queryUtil(mid + 1, end, l, r, 2 * node + 1);
        return leftAns + rightAns;
    }

    void update(int idx, int val) {
        updateUtil(0, n - 1, idx, val, 1);
    }

    void updateUtil(int start, int end, int idx, int val, int node) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) updateUtil(start, mid, idx, val, 2 * node);
        else updateUtil(mid + 1, end, idx, val, 2 * node + 1);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Sum of range [1,3]: " << st.query(1, 3) << endl; 
    cout << "Sum of range [0,5]: " << st.query(0, 5) << endl; 

    st.update(1, 10); 
    cout << "After update, sum of range [1,3]: " << st.query(1, 3) << endl; 
}
