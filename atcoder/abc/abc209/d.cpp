#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> v(n);
  auto f = [&](auto&& f, int i, int j) -> void {
    for (auto k : g[j]) {
      if (k == i) continue;
      v[k] = v[j] ^ 1;
      f(f, j, k);
    }
  };
  f(f, 0, 0);

  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << (v[a] == v[b] ? "Town" : "Road") << endl;
  }
}
