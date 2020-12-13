#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  int r = 1e9;
  vector dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) dp[i][0] = i;
  for (int j = 1; j <= m; j++) dp[0][j] = j;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
      r = min(r, dp[i][j] + (n - i) + (m - j));
    }
  }

  cout << r << endl;
}
