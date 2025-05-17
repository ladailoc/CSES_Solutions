#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

bool has_cycle(int v, vector<vector<int>>& graph, vector<int>& visited, vector<int>& rec_stack) {
    visited[v] = 1;
    rec_stack[v] = 1;

    for (int u : graph[v]) {
        if (!visited[u]) {
            if (has_cycle(u, graph, visited, rec_stack)) return true;
        } else if (rec_stack[u]) {
            return true;
        }
    }

    rec_stack[v] = 0;
    return false;
}

bool is_liar(int n, vector<int>& a) {
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            if (i > 0) add_edge(graph, i - 1, i);
            if (i < n - 1) add_edge(graph, i + 1, i);
        }
    }

    vector<int> visited(n + 1, 0), rec_stack(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && has_cycle(i, graph, visited, rec_stack)) {
            return true;
        }
    }

    // Kiểm tra trường hợp đặc biệt: tất cả đều báo cáo thắng
    bool all_win = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) all_win = false;
    }
    if (all_win && n > 1) return true; // Không thể tất cả đều thắng

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        cout << (is_liar(n, a) ? "YES\n" : "NO\n");
    }

    return 0;
}
