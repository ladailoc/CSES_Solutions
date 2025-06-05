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
    int n, x; cin >> n;
    vector<int> v(n);
    FOR(i,0,n) {
        cin >> v[i];
    }
    int l = 0, r = 0, mx = -1;
    map<int, int> mp;
    while (r < n) {
        while (mp[v[r]]) {
            mp.erase(v[l]);
            l++;
        }
        mp[v[r++]]++;
        mx = max(mx, r - l);
    }
    cout << mx;
    return 0;
}
