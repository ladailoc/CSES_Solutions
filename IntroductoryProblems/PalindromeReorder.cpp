    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define endl '\n'
    #define all(x) x.begin(), x.end()
    #define fi first
    #define se second

    const int MOD = 1e9 + 7;



    signed main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        string s; cin >> s;
        map<int, int> mp;
        for(auto x : s) {
            mp[x]++;
        }

        string ans = "", mid = "";
        for (auto [c, cnt] : mp) {
            if (cnt & 1) {
                if (mid != "") {
                    cout << "NO SOLUTION";
                    return 0;
                }
                mid = c;
            }
            ans += string(cnt / 2, c);
        }
        string rev = ans;
        reverse(all(ans));
        ans = ans + mid + rev;
        cout << ans;
        return 0;
    }
