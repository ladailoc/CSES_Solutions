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
    int x, n;
    cin >> x >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }

    set<int> se;
    multiset<int> segments;

    se.insert(0);
    se.insert(x);
    segments.insert(x);

    for (int p : pos) {
        auto upper = se.upper_bound(p);
        auto lower = prev(upper);

        int l = *lower;
        int r = *upper;

        segments.erase(segments.find(r - l));

        segments.insert(p - l);
        segments.insert(r - p);

        se.insert(p);

        cout << *segments.rbegin() << " ";
    }
    return 0;
}
