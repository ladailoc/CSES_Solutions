#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    vector<long long> dp(n + 1, 0);       // dp[i] = number of valid subsequences ending at i
    vector<long long> prefix(n + 1, 0);   // prefix[i] = dp[0] + ... + dp[i]

    unordered_map<int, int> last;         // last[x] = last occurrence index of x

    dp[0] = 1;         // empty subsequence
    prefix[0] = 1;

    for (int i = 1; i <= n; ++i) {
        int x = arr[i];

        if (last.find(x) != last.end()) {
            int j = last[x];
            dp[i] = (prefix[i - 1] - prefix[j - 1] + MOD) % MOD;
        } else {
            dp[i] = prefix[i - 1];
        }

        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
        last[x] = i;
    }

    // Subtract the empty subsequence
    cout << (prefix[n] - 1 + MOD) % MOD << endl;

    return 0;
}
