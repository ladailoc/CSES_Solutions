#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;

void solve(){
    int a, b; cin >> a >> b;
    if (a / 2 > b || b / 2 > a) {
        cout << "NO" << '\n';
    }
    else {
        if ((a + b) % 3 == 0){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
