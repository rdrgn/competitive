#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  dsu d(n);
  while (m--) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    g[p].push_back(q);
    g[q].push_back(p);
    d.merge(p, q);
  }

  auto groups = d.groups();
  vector<bool> is_initial(n);
  for (const auto e : groups) is_initial[*min_element(e.begin(), e.end())] = true;

  vector<int> color(n);
  auto f = [&](auto&& f, int i) -> ll {
    if (i == n) return 1;
    if (is_initial[i]) return 3 * f(f, i + 1);
    ll r = 0;
    for (int c = 0; c < 3; c++) {
      color[i] = c;
      bool valid = true;
      for (auto j : g[i]) {
        if (i < j) continue;
        if (color[i] == color[j]) valid = false;
      }
      if (!valid) continue;
      r += f(f, i + 1);
    }
    return r;
  };

  cout << f(f, 0) << endl;
}
