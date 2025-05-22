#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x; cin >> n;
    set<int> se;
    for(int i = 0; i < n; i++) {
        cin >> x;
        se.insert(x);
    }
    cout << se.size();
    return 0;
}
