#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x; cin >> n >> m;
    multiset<int> se;
    FOR(i, 0, n) {
        cin >> x;
        se.insert(x);
    }

    FOR(i, 0, m) {
        cin >> x;
        auto it = se.upper_bound(x);
        if (it != se.begin()) {
            it--;
            cout << *it << '\n';
            se.erase(it);
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
