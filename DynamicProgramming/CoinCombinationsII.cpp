#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int x;

    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);

    dp[0] = 1;

    for (int coin_val : coins) {
        for (int i = coin_val; i <= x; ++i) {
            dp[i] = (dp[i] + dp[i - coin_val]) % MOD;
        }
    }

    cout << dp[x] << std::endl;

    return 0;
}
