#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n, m;
  cin >> n >> m;

  int mn = max(n, m);
  vector p(mn + 1, vector<mint>(mn + 1));
  for (int i = 0; i <= mn; i++) {
    p[i][0] = 1;
    for (int j = 1; j <= mn; j++) p[i][j] = p[i][j - 1] * i;
  }

  mint r = 0;
  vector<mint> s(m + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      s[j] = s[j] * m + (i >= 1 ? p[m - j][i - 1] : 0);
      r += (p[m][i] - s[j]) * p[m][n - i - 1];
    }
  }
  cout << r.val() << endl;
}
