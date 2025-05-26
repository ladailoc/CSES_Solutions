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
    int n, x; cin >> n >> x;
    vector<pii> v(n);
    FOR(i,0,n) {
        cin >> v[i].fi;
        v[i].se = i+1;
    }

    sort(all(v));

    int i = 0, j = n-1;
    while (i != j) {
        if (v[i].fi + v[j].fi == x) {
            cout << v[i].se << " " << v[j].se << endl;
            return 0;
        }
        else if (v[i].fi + v[j].fi < x) {
            i++;
        }
        else j--;
    }

    cout << "IMPOSSIBLE";

    return 0;
}

