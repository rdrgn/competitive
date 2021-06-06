#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
  }

  int r = 0;
  vector<bool> v(n);
  auto f = [&](auto&& f, int i) -> void {
    r++;
    v[i] = true;
    for (auto e : g[i]) {
      if (v[e]) continue;
      f(f, e);
    }
  };
  for (int i = 0; i < n; i++) {
    fill(v.begin(), v.end(), false);
    f(f, i);
  }
  cout << r << endl;
}
