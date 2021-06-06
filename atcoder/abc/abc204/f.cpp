#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int h;
  ll w;
  cin >> h >> w;

  vector v(40, vector(1 << h, vector<mint>(1 << h)));
  auto f = [&](auto &&f, int i, int a, int b) -> void {
    if (i == h) {
      v[0][a][b]++;
      return;
    }
    int e = 1 << i, e2 = 1 << i + 1;
    f(f, i + 1, a, b);
    if (a & e) {
      f(f, i + 1, a ^ e, b);
      f(f, i + 1, a ^ e, b ^ e);
      if (a & e2) f(f, i + 1, a ^ e ^ e2, b);
    }
  };
  f(f, 0, (1 << h) - 1, 0);

  // for (int i = 0; i < (1 << h); i++) {
  //   for (int j = 0; j < (1 << h); j++) {
  //     cout << bitset<6>(i) << ' ' << bitset<6>(j) << ' ' << v[0][i][j].val() << endl;
  //   }
  // }

  for (int i = 1; i < v.size(); i++) {
    for (int a = 0; a < (1 << h); a++) {
      for (int b = 0; b < (1 << h); b++) {
        for (int c = 0; c < (1 << h); c++) {
          v[i][a][c] += v[i - 1][a][b] * v[i - 1][b][c];
        }
      }
    }
  }

  vector<mint> r(1 << h);
  r[0] = 1;
  while (w) {
    int i = 0;
    while ((1ll << i + 1) <= w) i++;
    vector<mint> t(1 << h);
    for (int a = 0; a < (1 << h); a++) {
      for (int b = 0; b < (1 << h); b++) {
        t[b] += r[a] * v[i][a][b];
      }
    }
    r = t;
    w -= 1ll << i;
  }
  cout << r[0].val() << endl;
}
