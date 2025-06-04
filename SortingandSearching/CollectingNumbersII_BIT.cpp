#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n), bit(n + 2, 0) {}

    void update(int i, int delta) {
        while (i <= n) {
            bit[i] += delta;
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

    BIT bit(n + 2);

    auto is_break = [&](int i) {
        return i >= 2 && pos[i] < pos[i - 1];
    };

    for (int i = 2; i <= n; ++i) {
        if (is_break(i)) bit.update(i, 1);
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        int x = arr[a];
        int y = arr[b];

        set<int> affected = {x, x + 1, y, y + 1};

        for (int i : affected) {
            if (is_break(i)) bit.update(i, -1);
        }

        swap(arr[a], arr[b]);

        pos[x] = b;
        pos[y] = a;

        for (int i : affected) {
            if (is_break(i)) bit.update(i, 1);
        }

        cout << 1 + bit.query(n) << '\n';
    }

    return 0;
}
