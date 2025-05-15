#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while (n--){
    	int x, y; cin >> x >> y;
    	int mx = max(x, y);
    	int mn = min(x, y);
    	int res = 0;
    	if (x == mx){
    		if (x % 2 != 0){
    			res = (x - 1) * (x - 1) + 1 + (y - 1);
			}
			else {
				res = x * x - (y - 1);
			}
		}
		else if (y == mx){
			if (y % 2 != 0){
				res = y * y - (x - 1);
			}
			else {
				res = (y - 1) * (y - 1) + 1 + (x - 1);
			}
		}
		cout << res << endl;
	}
    return 0;
}
