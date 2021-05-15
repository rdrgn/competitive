#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector a(60, vector<mint>(2, 0));
  auto f = [&](auto&& f, int i, int j, ll w) -> void {
    // cerr << j << ' ' << bitset<60>(w) << endl;
    for (int i = 0; i < a.size(); i++) {
      a[i][w >> i & 1]++;
    }
    for (auto e : g[j]) {
      if (e.first == i) continue;
      f(f, j, e.first, w ^ e.second);
    }
  };
  f(f, 0, 0, 0);

  // for (int i = 0; i < a.size(); i++) {
  //   for (auto e : a[i]) cerr << e.val() << ' ';
  //   cerr << endl;
  // }

  mint r = 0;
  for (int i = 0; i < a.size(); i++) r += mint(1ll << i) * (a[i][0] * a[i][1]);
  cout << r.val() << endl;
}
