#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  vector<ll> c(n);
  for (ll i = n - 1, xt = x; i >= 0; i--) {
    c[i] = xt / a[i];
    xt %= a[i];
  }

  vector dp(n + 1, vector<ll>(3));
  dp[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] += dp[i - 1][0];
    if (c[i - 1] != 0) dp[i][0] += dp[i - 1][1] + dp[i - 1][2];
    dp[i][1] += dp[i - 1][1] + dp[i - 1][2];
    if (i == n || c[i - 1] + 1 < a[i] / a[i - 1]) dp[i][2] += dp[i - 1][0];
  }
  cout << dp[n][1] + dp[n][2] << endl;
}
