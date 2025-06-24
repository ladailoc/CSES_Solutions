#include <bits/stdc++.h>
using namespace std;

struct Range {
    int a, b, idx;
};

int main() {
    int n;
    cin >> n;
    vector<Range> ranges(n);

    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].a >> ranges[i].b;
        ranges[i].idx = i;
    }

    // Sort by start ascending, end descending
    sort(ranges.begin(), ranges.end(), [](const Range &r1, const Range &r2) {
        if (r1.a == r2.a)
            return r1.b > r2.b;
        return r1.a < r2.a;
    });

    vector<int> contains(n), contained(n);

    // Check which ranges are contained in others
    int max_b = 0;
    for (const auto &r : ranges) {
        if (r.b <= max_b)
            contained[r.idx] = 1;
        max_b = max(max_b, r.b);
    }

    // Check which ranges contain others
    int min_b = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        const auto &r = ranges[i];
        if (r.b >= min_b)
            contains[r.idx] = 1;
        min_b = min(min_b, r.b);
    }

    for (int x : contains) cout << x << ' ';
    cout << '\n';
    for (int x : contained) cout << x << ' ';
    cout << '\n';

    return 0;
}
