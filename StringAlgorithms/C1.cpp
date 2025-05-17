#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;

    cout << "digit" << endl;
    cout.flush();
    int res; cin >> res;
    if (res == -1) exit(0);

    if (n > 100) {
        cout << "mul " << (n / 10 + 1) << endl;
        cout.flush();
        cin >> res;
        if (res == -1) exit(0);
    }

    cout << "add " << n << endl;
    cout.flush();
    cin >> res;
    if (res == -1) exit(0);

    cout << "div " << 2 << endl;
    cout.flush();
    cin >> res;
    if (res == -1) exit(0);

    cout << "!" << endl;
    cout.flush();
    cin >> res;
    if (res == -1) exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
