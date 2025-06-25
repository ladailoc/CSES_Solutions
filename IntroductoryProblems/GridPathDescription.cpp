#include <bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Duyệt qua từng hàng của lưới (từ 0 đến n-1)
    for (int i = 0; i < n; ++i) {
        // Duyệt qua từng cột của lưới trong hàng hiện tại (từ 0 đến n-1)
        for (int j = 0; j < n; ++j) {
            // Tính toán giá trị cho ô hiện tại bằng phép toán XOR bitwise (i ^ j)
            cout << (i ^ j);

            // In một dấu cách sau mỗi số, trừ số cuối cùng trong hàng
            if (j < n - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
