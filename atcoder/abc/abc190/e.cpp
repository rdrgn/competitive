#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e6;

int main() {
  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin >> k;
  vector<int> c(k);
  for (auto& e : c) cin >> e, e--;

  vector a(k, vector<int>(k));
  for (int i = 0; i < k; i++) {
    vector<int> d(n, INF);
    d[c[i]] = 0;
    queue<int> q;
    q.push(c[i]);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      for (auto e : g[p]) {
        if (d[p] + 1 < d[e]) {
          d[e] = d[p] + 1;
          q.push(e);
        }
      }
    }
    for (int j = 0; j < k; j++) a[i][j] = d[c[j]];
  }

  vector dp(1 << k, vector<int>(k, INF));
  for (int i = 0; i < k; i++) dp[1 << i][i] = 1;

  for (int b = 1; b < (1 << k); b++) {
    for (int i = 0; i < k; i++) {
      if (~b >> i & 1) continue;
      for (int j = 0; j < k; j++) {
        if (i == j || (b >> j & 1)) continue;
        dp[b | (1 << j)][j] = min(dp[b | (1 << j)][j], dp[b][i] + a[i][j]);
      }
    }
  }
  auto r = *min_element(dp[(1 << k) - 1].begin(), dp[(1 << k) - 1].end());
  cout << (r == INF ? -1 : r) << endl;
}
