#include <bits/stdc++.h>
using namespace std;

struct Range {
    int x, y, index;
};

bool cmpStart(const Range &a, const Range &b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end(), cmpStart);

    vector<int> contains(n), contained(n);

    // Check for "contained by some other range"
    int maxY = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (ranges[i].y <= maxY) {
            contained[ranges[i].index] = 1;
        }
        maxY = max(maxY, ranges[i].y);
    }

    // Check for "contains some other range"
    int minY = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (ranges[i].y >= minY) {
            contains[ranges[i].index] = 1;
        }
        minY = min(minY, ranges[i].y);
    }

    for (int i = 0; i < n; ++i)
        cout << contains[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i)
        cout << contained[i] << " ";
    cout << "\n";

    return 0;
}
