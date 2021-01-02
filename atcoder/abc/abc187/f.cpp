#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector a(n, vector<bool>(n));
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x][y] = a[y][x] = true;
  }

  vector<int> s;
  for (int b = 1; b < 1 << n; b++) {
    bool is_close = true;
    for (int i = 0; is_close && i < n; i++) {
      if (!(b >> i & 1)) continue;
      for (int j = i + 1; is_close && j < n; j++) {
        if (!(b >> j & 1)) continue;
        if (!a[i][j]) is_close = false;
      }
    }
    if (is_close) s.push_back(b);
  }

  vector<int> dp(1 << n, n);
  dp[0] = 0;
  for (int b = 0; b < 1 << n; b++) {
    if (dp[b] + 1 >= dp[(1 << n) - 1]) continue;
    for (auto e : s) {
      if (b & e) continue;
      dp[b | e] = min(dp[b | e], dp[b] + 1);
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}
