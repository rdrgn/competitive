#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s, x;
  cin >> n >> s >> x;

  vector<int> a(n);
  for (int i = n - 1, p = 1; i >= 0; i--, p = p * 10 % 7) a[i] = (s[i] - '0') * p % 7;

  vector<bitset<7>> dp(n + 1);
  dp[n][0] = true;
  for (int i = n - 1; i >= 0; i--) {
    auto e0 = dp[i + 1];
    auto e1 = (e0 << a[i]) | (e0 >> 7 - a[i]);
    if (x[i] == 'T') {
      dp[i] = e0 | e1;
    } else {
      dp[i] = e0 & e1;
    }
  }
  cout << (dp[0][0] ? "Takahashi" : "Aoki") << endl;
}
