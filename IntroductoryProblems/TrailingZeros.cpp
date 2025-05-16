#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int dem2 = 0, dem5 = 0;
    for (int i = 2; i <= n; i *= 2)
        dem2 += n / i;
    for (int i = 5; i <= n; i *= 5)
        dem5 += n / i;
    cout << min(dem2, dem5);
    return 0;
}
