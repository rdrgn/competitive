#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  vector v(h, vector<bool>(w));
  auto dfs = [&](auto&& dfs, int i, int j, int a) -> ll {
    if (j >= w) return dfs(dfs, i + 1, 0, a);
    if (i >= h) return a == 0 ? 1 : 0;
    ll r = 0;
    r += dfs(dfs, i, j + 1, a);
    if (a > 0) {
      if (0 <= i - 1 && !v[i - 1][j]) {
        v[i - 1][j] = v[i][j] = true;
        r += dfs(dfs, i, j + 1, a - 1);
        v[i - 1][j] = v[i][j] = false;
      }
      if (0 <= j - 1 && !v[i][j - 1]) {
        v[i][j - 1] = v[i][j] = true;
        r += dfs(dfs, i, j + 1, a - 1);
        v[i][j - 1] = v[i][j] = false;
      }
    }
    return r;
  };
  cout << dfs(dfs, 0, 0, a) << endl;
}
