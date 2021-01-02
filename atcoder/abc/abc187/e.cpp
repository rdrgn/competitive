#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;

using S = ll;

S op(S a, S b) { return a + b; }

S e() { return 0; }

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n - 1);
  vector<vector<int>> g(n);
  for (auto& e : a) {
    cin >> e.first >> e.second;
    e.first--, e.second--;
    g[e.first].push_back(e.second);
    g[e.second].push_back(e.first);
  }

  vector<int> nodes;
  vector<pair<int, int>> ranges(n);
  auto dfs = [&](auto&& dfs, int i, int j) -> void {
    ranges[j].first = nodes.size();
    nodes.push_back(j);
    for (auto k : g[j]) {
      if (k == i) continue;
      dfs(dfs, j, k);
    }
    ranges[j].second = nodes.size();
  };
  dfs(dfs, 0, 0);

  lazy_segtree<S, op, e, S, op, op, e> seg(n);

  int q;
  cin >> q;
  while (q--) {
    ll t, e, x;
    cin >> t >> e >> x;
    e--;
    auto r1 = ranges[t == 1 ? a[e].first : a[e].second];
    auto r2 = ranges[t == 1 ? a[e].second : a[e].first];
    if (r2.first <= r1.first && r1.second <= r2.second) {
      seg.apply(r1.first, r1.second, x);
    } else {
      seg.apply(0, r2.first, x);
      seg.apply(r2.second, n, x);
    }
  }

  vector<ll> r(n);
  for (int i = 0; i < n; i++) r[nodes[i]] = seg.get(i);

  for (auto e : r) cout << e << endl;
}
