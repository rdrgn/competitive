#include <bits/stdc++.h>
using namespace std;

template <class T>
void set_if_less(T& a, T b) {
  if (a > b) a = b;
}

void solve() {
  int x, y;
  string s;
  cin >> x >> y >> s;
  int n = s.size();

  vector dp(n, vector<int>(2, 1e9));
  if (s[0] != 'J') dp[0][0] = 0;
  if (s[0] != 'C') dp[0][1] = 0;

  for (int i = 1; i < n; i++) {
    if (s[i] != 'J') set_if_less(dp[i][0], min(dp[i - 1][0], dp[i - 1][1] + y));
    if (s[i] != 'C') set_if_less(dp[i][1], min(dp[i - 1][0] + x, dp[i - 1][1]));
  }
  cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
