#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<pair<int, int>, vector<int>> v;
  while (m--) {
    int p, q, c;
    cin >> p >> q >> c;
    if (p > q) swap(p, q);
    v[{p - 1, q - 1}].push_back(c);
  }

  vector<vector<pair<int, int>>> g(n);
  for (const auto& e : v) {
    g[e.first.first].push_back({e.first.second, e.second.front()});
    g[e.first.second].push_back({e.first.first, e.second.front()});
  }

  vector<int> r(n);
  auto dfs = [&](auto&& dfs, int i, int j, int c, bool b) -> void {
    if (b) {
      r[j] = c;
    } else if (g[j].size() == 1 && g[j][0].first == i) {
      r[j] = g[j][0].second != 1 ? 1 : 2;
    } else {
      r[j] = g[j][0].first != i ? g[j][0].second : g[j][1].second;
      if (r[j] == c) r[j] = c != 1 ? 1 : 2;
    }
    for (auto e : g[j]) {
      if (r[e.first]) continue;
      dfs(dfs, j, e.first, e.second, r[j] != e.second);
    }
  };
  dfs(dfs, 0, 0, 0, false);

  for (auto e : r) cout << e << endl;
}
