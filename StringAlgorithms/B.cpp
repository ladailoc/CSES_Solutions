#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
long long a[N], threat[N], dp[N][2]; // dp[u][0] = max sum starting with +, dp[u][1] = max sum starting with -
int parent[N];

void dfs(int u, int p) {
    parent[u] = p;

    dp[u][0] = a[u];
    dp[u][1] = -a[u];

    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);

        dp[u][0] = max(dp[u][0], a[u] + dp[v][1]);
        dp[u][1] = max(dp[u][1], dp[v][0] - a[u]);
    }

    threat[u] = a[u];
    long long current = a[u];
    int v = u;
    int sign = -1;

    while(v != 0) {
        v = parent[v];
        if(v == 0) break;
        current += sign * a[v];
        threat[u] = max(threat[u], current);
        sign *= -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            adj[i].clear();
            threat[i] = 0;
            parent[i] = 0;
            dp[i][0] = dp[i][1] = 0;
        }

        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);

        for(int i = 1; i <= n; i++) {
            cout << threat[i];
            if(i < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
