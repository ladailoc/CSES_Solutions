#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<int> dp(m + 1, 0);

    if (x[0] == 0) {
        for (int j = 1; j <= m; ++j) {
            dp[j] = 1;
        }
    } else {
        dp[x[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        vector<int> next_dp(m + 1, 0);

        if (x[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                if (j - 1 >= 1) {
                    next_dp[j] = (next_dp[j] + dp[j - 1]) % MOD;
                }
                next_dp[j] = (next_dp[j] + dp[j]) % MOD;
                if (j + 1 <= m) {
                    next_dp[j] = (next_dp[j] + dp[j + 1]) % MOD;
                }
            }
        } else {
            int val = x[i];
            if (val - 1 >= 1) {
                next_dp[val] = (next_dp[val] + dp[val - 1]) % MOD;
            }
            next_dp[val] = (next_dp[val] + dp[val]) % MOD;
            if (val + 1 <= m) {
                next_dp[val] = (next_dp[val] + dp[val + 1]) % MOD;
            }
        }
        dp = next_dp;
    }

    int total_arrays = 0;
    for (int j = 1; j <= m; ++j) {
        total_arrays = (total_arrays + dp[j]) % MOD;
    }

    cout << total_arrays << '\n';

    return 0;
}
