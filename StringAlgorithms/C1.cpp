#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        int initialMinX = *min_element(x.begin(), x.end());
        int initialMaxX = *max_element(x.begin(), x.end());
        int initialMinY = *min_element(y.begin(), y.end());
        int initialMaxY = *max_element(y.begin(), y.end());
        int initialArea = (initialMaxX - initialMinX + 1) * (initialMaxY - initialMinY + 1);
        int ans = initialArea;

        for (int i = 0; i < n; i++) {
            vector<int> xOthers, yOthers;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    xOthers.push_back(x[j]);
                    yOthers.push_back(y[j]);
                }
            }

            if (xOthers.empty()) continue;

            int minX = *min_element(xOthers.begin(), xOthers.end());
            int maxX = *max_element(xOthers.begin(), xOthers.end());
            int minY = *min_element(yOthers.begin(), yOthers.end());
            int maxY = *max_element(yOthers.begin(), yOthers.end());

            for (int j = 0; j < xOthers.size(); j++) {
                int newX = xOthers[j];
                vector<int> yTry = {minY - 1, minY, maxY, maxY + 1};
                for (int newY : yTry) {
                    bool occupied = false;
                    for (int k = 0; k < n; k++) {
                        if (k == i) continue;
                        if (x[k] == newX && y[k] == newY) {
                            occupied = true;
                            break;
                        }
                    }
                    if (occupied) continue;

                    int newMinX = min(minX, newX);
                    int newMaxX = max(maxX, newX);
                    int newMinY = min(minY, newY);
                    int newMaxY = max(maxY, newY);
                    int area = (newMaxX - newMinX + 1) * (newMaxY - newMinY + 1);
                    ans = min(ans, area);
                }
            }

            for (int j = 0; j < yOthers.size(); j++) {
                int newY = yOthers[j];
                vector<int> xTry = {minX - 1, minX, maxX, maxX + 1};
                for (int newX : xTry) {
                    bool occupied = false;
                    for (int k = 0; k < n; k++) {
                        if (k == i) continue;
                        if (x[k] == newX && y[k] == newY) {
                            occupied = true;
                            break;
                        }
                    }
                    if (occupied) continue;

                    int newMinX = min(minX, newX);
                    int newMaxX = max(maxX, newX);
                    int newMinY = min(minY, newY);
                    int newMaxY = max(maxY, newY);
                    int area = (newMaxX - newMinX + 1) * (newMaxY - newMinY + 1);
                    ans = min(ans, area);
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
