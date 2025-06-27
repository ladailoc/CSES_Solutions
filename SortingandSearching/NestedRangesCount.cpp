#include <bits/stdc++.h>
using namespace std;

struct Range {
    int x, y, idx;
};

bool cmp_contains(const Range &a, const Range &b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

bool cmp_contained(const Range &a, const Range &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x > b.x;
}

class Fenwick {
    vector<int> bit;
public:
    Fenwick(int n) : bit(n + 2, 0) {}
    void update(int i, int v) {
        while (i < bit.size()) {
            bit[i] += v;
            i += i & -i;
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
    int query_range(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Range> a(n);
    vector<int> ys;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].idx = i;
        ys.push_back(a[i].y);
    }

    // Coordinate compression
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    auto compress = [&](int y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
    };

    vector<int> contains(n), contained(n);

    // Contains
    sort(a.begin(), a.end(), cmp_contains);
    Fenwick bit(ys.size());
    for (int i = n - 1; i >= 0; ) {
        int j = i;
        int cy = compress(a[i].y);
        while (j >= 0 && a[j].x == a[i].x && a[j].y == a[i].y) --j;

        for (int k = j + 1; k <= i; ++k)
            contains[a[k].idx] = bit.query(cy);
        for (int k = j + 1; k <= i; ++k)
            bit.update(cy, 1);

        i = j;
    }

    // Contained
    sort(a.begin(), a.end(), cmp_contained);
    bit = Fenwick(ys.size());
    for (int i = 0; i < n; ) {
        int j = i;
        int cy = compress(a[i].y);
        while (j < n && a[j].x == a[i].x && a[j].y == a[i].y) ++j;

        for (int k = i; k < j; ++k)
            contained[a[k].idx] = bit.query(ys.size()) - bit.query(cy - 1);
        for (int k = i; k < j; ++k)
            bit.update(cy, 1);

        i = j;
    }

    for (int x : contains) cout << x << " ";
    cout << "\n";
    for (int x : contained) cout << x << " ";
    cout << "\n";
}
