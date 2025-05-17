#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fi first
#define se second

const int MOD = 1e9 + 7;



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < 1 << n; i++){
        int gray = i ^ (i >> 1);
        cout << bitset<32>(gray).to_string().substr(32 - n) << '\n';
    }
    return 0;
}
