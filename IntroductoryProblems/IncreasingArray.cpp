#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int mx, x, tong = 0;
    cin >> mx;
    for (int i = 0; i < n - 1; i++){
    	cin >> x;
    	if (x < mx)
    		tong += mx - x;
    	mx = max (mx, x);
	}

	cout << tong;
    return 0;
}
