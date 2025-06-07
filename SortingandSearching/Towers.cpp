#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> towers;

    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        auto it = towers.upper_bound(k);

        if (it != towers.end()) {
            cout << *it << endl;
            towers.erase(it);

        }
        towers.insert(k);
    }

    cout << towers.size() << endl;
    return 0;
}


/*
10
10 4 5 9 4 10 2 7 4 6


  4 2 4 6
*/
