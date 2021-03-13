#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAX = 1e9;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<ll, ll>> a(n);
  vector<ll> b(m);
  for (auto& e : a) cin >> e.first >> e.second;
  for (auto& e : b) cin >> e;

  mcf_graph<ll, ll> g0(n + m + 2);
  for (int i = 0; i < n; i++) g0.add_edge(0, 1 + i, 1, MAX - a[i].second);
  for (int i = 0; i < m; i++) g0.add_edge(1 + n + i, 1 + n + m, 1, 0);

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;

    auto g = g0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (l <= j && j < r) continue;
        if (a[i].first > b[j]) continue;
        g.add_edge(1 + i, 1 + n + j, 1, 0);
      }
    }
    auto p = g.flow(0, 1 + n + m);
    cout << MAX * p.first - p.second << endl;
  }
}
