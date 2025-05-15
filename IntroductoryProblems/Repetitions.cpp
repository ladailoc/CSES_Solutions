#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x; cin >> x;
    int cnt = 1, mx = 1;
    for (int i = 0; i < x.size() - 1; i++){
    	if (x[i] == x[i + 1])
    		cnt++;
    	else {
    		mx = max (mx, cnt);
    		cnt = 1;
		}
	}

	cout << max(mx, cnt);
    return 0;
}
