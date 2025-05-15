#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
	int tong = (n + 1) * n / 2;
	if (tong % 2 != 0 ){
		cout << "NO";
	}
	else {
		cout << "YES" << endl;
 		tong /= 2;
		set<int> a, b;
		for (int i = n; i > 0; i--){
			if (i <= tong) {
				tong -= i;
				a.insert(i);
			}
			else b.insert(i);
		}

		cout << a.size() << endl;
		for(auto x : a) cout << x << " ";
		cout << endl;
		cout << b.size() << endl;
		for(auto x : b) cout << x << " ";
	}
    return 0;
}
