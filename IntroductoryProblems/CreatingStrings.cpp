#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
string ans, s;
int n, used[9];
set<string> se;
void Try(int i) {
    if (i == s.size()){
        se.insert(ans);
        return;
    }
    for (int j = 0; j < s.size(); j++){
        if (!used[j]) {
            ans.push_back(s[j]);
            used[j] = 1;
            Try(i + 1);
            used[j] = 0;
            ans.pop_back();
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    Try(0);
    cout << se.size() << endl;
    for(auto x: se) cout << x << endl;

    return 0;
}
