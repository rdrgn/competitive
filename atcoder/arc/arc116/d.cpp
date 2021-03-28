#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n, m;
  cin >> n >> m;

  vector c(n + 1, vector<mint>(n + 1));
  for (int i = 0; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }

  vector<mint> dp(m + 1);
  dp[0] = 1;
  for (int b = 1; 2 * b <= m; b <<= 1) {
    vector<mint> t(m + 1);
    for (int j = 2; j <= n; j += 2) {
      for (int i = m - j * b; i >= 0; i--) {
        t[i + j * b] += dp[i] * c[n][j];
      }
    }
    for (int i = 0; i <= m; i++) dp[i] += t[i];
  }
  cout << dp[m].val() << endl;
}
