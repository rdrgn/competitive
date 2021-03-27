#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  auto dfs = [&](auto&& dfs, int i, int x, int o) -> int {
    if (i == n) return x ^ o;
    return min(dfs(dfs, i + 1, x, o | a[i]), dfs(dfs, i + 1, x ^ o, a[i]));
  };
  cout << dfs(dfs, 0, 0, 0) << endl;
}
