#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    if (n == 3 || n == 2) {
    	cout << "NO SOLUTION";
	}
	else {
		for (int i = n - 1; i > 0; i -= 2){
			cout << i << " ";
		}
		for (int i = n; i > 0; i-=2)
			cout << i << " ";
	}
    return 0;
}
