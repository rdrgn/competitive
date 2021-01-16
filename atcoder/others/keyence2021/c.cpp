#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector s(h, string(w, '.'));
  while (k--) {
    int i, j;
    char c;
    cin >> i >> j >> c;
    s[i - 1][j - 1] = c;
  }

  vector r(h + 1, vector<int>(w + 1));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') r[i][j] = 1;
    }
  }
  auto d = r;
  for (int i = h - 1; i >= 0; i--) {
    for (int j = w - 1; j >= 0; j--) {
      r[i][j] += r[i][j + 1];
      d[i][j] += d[i + 1][j];
    }
  }

  vector<mint> p3(max(h, w));
  p3[0] = 1;
  for (int i = 1; i < p3.size(); i++) p3[i] = 3 * p3[i - 1];

  vector dp(h + 1, vector<mint>(w + 1));
  dp[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      switch (s[i][j]) {
        case 'R': {
          dp[i][j + 1] += p3[d[i + 1][j]] * dp[i][j];
          break;
        }
        case 'D': {
          dp[i + 1][j] += p3[r[i][j + 1]] * dp[i][j];
          break;
        }
        case 'X': {
          dp[i][j + 1] += p3[d[i + 1][j]] * dp[i][j];
          dp[i + 1][j] += p3[r[i][j + 1]] * dp[i][j];
          break;
        }
        default: {
          dp[i][j + 1] += 2 * p3[d[i + 1][j]] * dp[i][j];
          dp[i + 1][j] += 2 * p3[r[i][j + 1]] * dp[i][j];
          break;
        }
      }
    }
  }
  if (s[h - 1][w - 1] == '.') dp[h - 1][w - 1] *= 3;
  cout << dp[h - 1][w - 1].val() << endl;
}
