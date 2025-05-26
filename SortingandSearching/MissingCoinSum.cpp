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
    vector<int> v(n);
    FOR(i,0,n) {
        cin >> v[i];
    }

    sort(all(v));
    int res = 1;
    FOR(i, 0, n) {
        if (v[i] > res) {
            break;
        }
        else res += v[i];
    }
    cout << res;
    return 0;
}

