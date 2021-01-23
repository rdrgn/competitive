#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto& e : s) cin >> e;

  vector dp(n + 1, vector<ll>(2));
  dp[0][0] = dp[0][1] = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == "AND") {
      dp[i + 1][0] += 2 * dp[i][0] + dp[i][1];
      dp[i + 1][1] += dp[i][1];
    } else {
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][0] + 2 * dp[i][1];
    }
  }
  cout << dp[n][1] << endl;
}
