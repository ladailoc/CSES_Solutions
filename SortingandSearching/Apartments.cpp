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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    sort(all(a));
    sort(all(b));
    int i = 0, j = 0, cnt = 0;
    while (j < m && i < n) {
        if (b[j] - k <= a[i] && b[j] + k >= a[i]){
            cnt++; i++, j++;
            continue;
        }
        if (b[j] - k > a[i]){
            i++;
        }
        if (b[j] + k < a[i]){
            j++;
        }
    }
    cout << cnt;
    return 0;
}
