#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
const int MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    if (grid[0][0] == '.') {
        dp[0][0] = 1;
    }

    for (int j = 1; j < n; ++j) {
        if (grid[0][j] == '.' && grid[0][j - 1] == '.') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == '.' && grid[i - 1][0] == '.') {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
