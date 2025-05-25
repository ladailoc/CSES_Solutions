#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n;
    vector<int> v(n);
    FOR(i,0,n) {
        cin >> v[i];
    }
    sort(all(v));

    int l = 0, r = n - 1, mn = INT_MAX;
    while (l <= r) {
        if ((v[l] + v[r]) % 2 == 0){
            mn = min(mn, n - r - 1);
            break;
        }
        r--;
    }
    r = n - 1;
    while (l <= r) {
        if ((v[l] + v[r]) % 2 == 0){
            mn = min(mn, l);
            break;
        }
        l++;
    }
    cout << mn << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
