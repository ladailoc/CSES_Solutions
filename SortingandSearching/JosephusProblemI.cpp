#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;
    vector<int> result;

    for (int i = 1; i <= n; ++i)
        dq.push_back(i);
    while (!dq.empty()) {
        dq.push_back(dq.front());
        dq.pop_front();

        result.push_back(dq.front());
        dq.pop_front();
    }

    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << result[i];
    }
    cout << '\n';

    return 0;
}
