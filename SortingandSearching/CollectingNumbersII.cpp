#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    auto count_rounds = [&]() {
        int rounds = 1;
        for (int i = 2; i <= n; ++i) {
            if (pos[i] < pos[i - 1]) {
                ++rounds;
            }
        }
        return rounds;
    };

    int rounds = count_rounds();

    while (m--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int x = arr[a];
        int y = arr[b];

        set<int> affected = {x, x - 1, x + 1, y, y - 1, y + 1};

        for (int val : affected) {
            if (val > 1 && val <= n) {
                if (pos[val] < pos[val - 1]) --rounds;
            }
        }

        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);

        for (int val : affected) {
            if (val > 1 && val <= n) {
                if (pos[val] < pos[val - 1]) ++rounds;
            }
        }

        cout << rounds << '\n';
    }

    return 0;
}

/*
5 3
4 2 1 5 3
2 3
1 5
2 3
*/
