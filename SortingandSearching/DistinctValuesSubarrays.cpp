#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
const int MOD = 1e9 + 7;

int countDistinctSubarrays(int n, const vector<int>& arr) {
    unordered_set<int> seen;
    int left = 0, result = 0;

    for (int right = 0; right < n; ++right) {
        while (seen.count(arr[right])) {
            seen.erase(arr[left]);
            left++;
        }

        seen.insert(arr[right]);

        result += (right - left + 1);
    }

    return result;
}

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << countDistinctSubarrays(n, arr) << '\n';
    return 0;
}
