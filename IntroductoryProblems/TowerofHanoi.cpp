#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()

vector<string> str;
 void tower(int n, int l, int m, int r){
    if (n == 0) return;
    tower(n-1, l, r, m);
    str.push_back(to_string(l) + " " + to_string(r));
    tower(n-1, m, l, r);
 }


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    tower(n, 1, 2, 3);
    cout << str.size() << endl;
    for (auto x : str) cout << x << endl;
    return 0;
}
