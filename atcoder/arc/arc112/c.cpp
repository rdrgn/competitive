#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int e;
    cin >> e;
    e--;
    g[i].push_back(e);
    g[e].push_back(i);
  }

  auto f = [](pair<int, int> x, pair<int, int> y) { return x.first - x.second < y.first - y.second; };

  vector<int> a(n), b(n), t(n);
  auto dfs = [&](auto&& dfs, int i) -> void {
    a[i] += 1;
    t[i] ^= 1;
    vector<pair<int, int>> u, v;
    for (auto j : g[i]) {
      if (j < i) continue;
      dfs(dfs, j);
      (t[j] ? v : u).push_back({b[j], a[j]});
    }
    sort(u.begin(), u.end(), f);
    sort(v.begin(), v.end(), f);
    while (!u.empty() || !v.empty()) {
      if (!u.empty() && u.back().first > u.back().second || v.empty()) {
        a[i] += t[i] ? u.back().second : u.back().first;
        b[i] += t[i] ? u.back().first : u.back().second;
        u.pop_back();
      } else {
        a[i] += t[i] ? v.back().second : v.back().first;
        b[i] += t[i] ? v.back().first : v.back().second;
        t[i] ^= 1;
        v.pop_back();
      }
    }
  };
  dfs(dfs, 0);
  cout << a[0] << endl;
}
