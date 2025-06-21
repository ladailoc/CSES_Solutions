#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;

    int max_freq = *max_element(freq.begin(), freq.end());
    if (max_freq > (n + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }

    string result = "";
    char last_char = '#';

    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 26; ++c) {
            if (freq[c] == 0) continue;
            if (last_char - 'A' == c) continue;

            freq[c]--;
            int remaining = n - i - 1;
            int max_remaining = *max_element(freq.begin(), freq.end());

            if (max_remaining <= (remaining + 1) / 2) {
                result += (char)(c + 'A');
                last_char = (char)(c + 'A');
                break;
            }

            freq[c]++;
        }
    }

    cout << result << endl;
    return 0;
}
