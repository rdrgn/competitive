#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

void set_if_greater(ll& a, ll b) {
  if (a == INF || a < b) a = b;
}

int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  vector dp(n + 1, vector(n + 1, vector(n + 1, vector<ll>(n + 1, INF))));
  fill(dp[0][0][0].begin(), dp[0][0][0].end(), 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int m = 1; m <= n; m++) {
          if (dp[i][j][k][m] == INF) continue;
          set_if_greater(dp[i + 1][j][k][m], dp[i][j][k][m]);

          auto t = dp[i][j][k][m] + a[i];
          set_if_greater(dp[i + 1][j + 1][t % m][m], t);
        }
      }
    }
  }

  ll r = INF;
  for (int j = 1; j <= n; j++) {
    if (dp[n][j][x % j][j] == INF) continue;
    r = min(r, (x - dp[n][j][x % j][j]) / j);
  }
  cout << r << endl;
}
