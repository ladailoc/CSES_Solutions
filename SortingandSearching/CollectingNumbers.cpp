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
    int n; cin >> n;
    vector<int> v(n);
    FOR(i, 0, n) {
        int x; cin >> x;
        x--;
        v[x] = i;
    }
    int cnt = 1;
    FOR(i, 1 , n) {
        if (v[i] < v[i-1])
            cnt++;
    }
    cout << cnt;
    return 0;
}
