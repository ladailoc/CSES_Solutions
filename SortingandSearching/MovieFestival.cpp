#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fi first
#define se second
#define pii pair<int, int>

const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pii> v;
    FOR(i,0,n) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(all(v), [](pii a, pii b) {
            return a.se < b.se;
         });

    pii cur = v[0];
    int cnt = 1;
    FOR(i, 1, n) {
        if (cur.se <= v[i].fi) {
            cur = v[i];
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}

