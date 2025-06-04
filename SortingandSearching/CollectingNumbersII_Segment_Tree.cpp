#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int _n) : n(_n), tree(4 * n, 0) {}

    void update(int idx, int val, int v=1, int tl=1, int tr=-1) {
        if (tr == -1) tr = n;
        if (tl == tr) {
            tree[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (idx <= tm) update(idx, val, v*2, tl, tm);
        else update(idx, val, v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }

    int query(int l, int r, int v=1, int tl=1, int tr=-1) {
        if (tr == -1) tr = n;
        if (r < tl || tr < l) return 0;
        if (l <= tl && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return query(l, r, v*2, tl, tm) + query(l, r, v*2+1, tm+1, tr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> pos(n + 2);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    SegmentTree seg(n + 2);

    auto is_break = [&](int i) {
        return i >= 2 && pos[i] < pos[i - 1];
    };

    for (int i = 2; i <= n; ++i) {
        seg.update(i, is_break(i) ? 1 : 0);
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int x = arr[a];
        int y = arr[b];

        set<int> affected = {x, x + 1, y, y + 1};

        for (int i : affected) {
            if (i >= 2 && i <= n) {
                seg.update(i, 0);
            }
        }

        swap(arr[a], arr[b]);
        pos[x] = b;
        pos[y] = a;

        for (int i : affected) {
            if (i >= 2 && i <= n) {
                seg.update(i, is_break(i) ? 1 : 0);
            }
        }

        cout << 1 + seg.query(1, n) << '\n';
    }

    return 0;
}
