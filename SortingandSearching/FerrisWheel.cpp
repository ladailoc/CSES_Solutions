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
    int n, x, k; cin >> n >> x;

    multiset<int> se;
    FOR(i, 0, n){
        cin >> k;
        se.insert(k);
    }
    int cnt = 0;
    while(se.size() != 0){
        auto left = se.begin();
        auto it = se.upper_bound(x - *left);
        if (it != left) {
            it--;
            if (*left + *it <= x && it != left) {
                se.erase(it);
            }
        }
        se.erase(left);
        cnt++;
    }

    cout << cnt;
    return 0;
}
