#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll solve(ll n, ll m, ll a, ll b) {
    // Initial analysis:
    // - Mouf wants to minimize turns (will cut the larger dimension first)
    // - Fouad wants to maximize turns (will move to avoid cuts)

    // We can prove that optimal play leads to this pattern:
    // 1. Mouf always cuts the larger dimension in half
    // 2. Fouad always positions his monster optimally after each cut

    long long turns = 0;

    // Continue until we have a 1x1 grid
    while (n > 1 || m > 1) {
        turns++;

        if (n >= m) {
            // If rows >= columns, Mouf cuts rows
            n = (n + 1) / 2;
        } else {
            // Otherwise Mouf cuts columns
            m = (m + 1) / 2;
        }
    }

    return turns;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n, m, a, b; cin >> n >> m >> a >> b;
        cout << solve(n, m, a, b) << '\n';
    }

    return 0;
}
