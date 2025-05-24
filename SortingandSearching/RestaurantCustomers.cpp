#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fi first
#define se second
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> p;
    FOR(i, 0, n) {
        int a, b; cin >> a >> b;
        p.push_back({b, a});
    }

    sort(all(p), [](pair<int, int> a, pair<int, int> b) {
            return a.fi < b.fi;
        });

    multimap<int, int> mp;
    FOR(i, 0, n){
        auto it = mp.upper_bound(p[i].se);
        if (it != mp.begin()) {
            it--;
            mp.erase(it);
        }
        mp.insert({p[i].fi, p[i].se});
    }
    cout << mp.size();
    return 0;
}

/*
3
5 8
2 4
3 9
*/
