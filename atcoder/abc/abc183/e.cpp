#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  const int di[] = {0, -1, -1};
  const int dj[] = {-1, 0, -1};
  vector dp(h + 1, vector(w + 1, vector<mint>(4)));
  dp[1][1][3] = 1;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (s[i - 1][j - 1] == '#') continue;
      for (int k = 0; k < 3; k++) {
        int i2 = i + di[k], j2 = j + dj[k];
        for (int k2 = 0; k2 < 4; k2++) dp[i][j][k] += (k == k2 ? 2 : 1) * dp[i2][j2][k2];
      }
    }
  }
  cout << accumulate(dp[h][w].begin(), dp[h][w].end(), mint()).val() << endl;
}
