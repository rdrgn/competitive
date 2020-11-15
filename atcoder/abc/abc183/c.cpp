#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector t(n, vector<int>(n));
  for (auto& e : t) {
    for (auto& e : e) cin >> e;
  }

  auto dfs = [&](auto&& dfs, int b, int i, int c) -> int {
    if (b == (1 << n) - 1) return c + t[i][0] == k;
    int r = 0;
    for (int j = 0; j < n; j++) {
      if (b >> j & 1) continue;
      r += dfs(dfs, b | 1 << j, j, c + t[i][j]);
    }
    return r;
  };

  cout << dfs(dfs, 1, 0, 0) << endl;
}
