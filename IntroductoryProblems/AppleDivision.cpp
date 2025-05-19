#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, total = 0; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }

    int t = 0, mn = INT_MAX;
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++){
            if (i & (1 << j)) {
                t += a[j];
            }
        }
        mn = min(mn, abs(total - 2 * t));
        t = 0;
    }
    cout << mn;
    return 0;
}
