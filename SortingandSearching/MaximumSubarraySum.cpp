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
    int n, x; cin >> n;
    int ans, mx;
    cin >> ans;
    mx = ans;
    FOR(i,1,n) {
        cin >> x;
        ans += x;
        ans = max (ans, x);
        mx = max(mx, ans);
    }

    cout << mx;

    return 0;
}

