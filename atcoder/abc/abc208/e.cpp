#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  ll k;
  cin >> s >> k;

  int n = s.size();

  vector dp(n + 1, vector(2, vector<map<ll, ll>>(2)));
  dp[0][0][0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int l = 0; l < 2; l++) {
        for (auto e : dp[i][j][l]) {
          for (int d = 0; d <= (j ? 9 : s[i] - '0'); d++) {
            dp[i + 1][j || d < s[i] - '0' ? 1 : 0][l || d ? 1 : 0][l || d ? min(e.first * d, k + 1) : e.first] +=
                e.second;
          }
        }
      }
    }
  }

  // for (int i = 0; i < n; i++) {
  //   cerr << i << endl;
  //   for (int j = 0; j < 2; j++) {
  //     cerr << j << ": ";
  //     for (auto e : dp[i + 1][j][1]) cerr << e.first << ',' << e.second << ' ';
  //     cerr << endl;
  //   }
  // }

  ll r = 0;
  for (int j = 0; j < 2; j++) {
    for (auto e : dp[n][j][1]) {
      if (e.first <= k) r += e.second;
    }
  }
  cout << r << endl;
}
