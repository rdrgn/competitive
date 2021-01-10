#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9 + 1;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& e : a) cin >> e;
  vector<vector<int>> g(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
  }

  int r = -INF;
  vector<int> v(n, INF);
  for (int i = 0; i < n; i++) {
    for (auto j : g[i]) v[j] = min({v[j], v[i], a[i]});
    if (v[i] != INF) r = max(r, a[i] - v[i]);
  }
  cout << r << endl;
}
