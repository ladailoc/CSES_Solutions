#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
int c[8][8], cnt = 0;
vector<int> used_hang, used_cheo_chinh, used_cheo_phu;
void Try(int i) {
    if (i == 8) {
        cnt++;
        return;
    }
    for (int j = 0; j < 8; j++) {
        if (!used_hang[j] && !used_cheo_chinh[i + j - 1] && !used_cheo_phu[i - j + 8] && !c[i][j]) {
            used_cheo_chinh[i + j - 1] = used_cheo_phu[i - j + 8] = used_hang[i] = c[i][j] = 1;
            Try(i+1);
            used_cheo_chinh[i + j - 1] = used_cheo_phu[i - j + 8] = used_hang[i] = c[i][j] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char x;
    used_hang.resize(9, 0);
    used_cheo_chinh.resize(17, 0);
    used_cheo_phu.resize(17, 0);

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> x;
            if (x == '.'){
                c[i][j] = 0;
            }
            else c[i][j] = 1;
        }
    }

    Try(0);
    cout << cnt;


    return 0;
}
