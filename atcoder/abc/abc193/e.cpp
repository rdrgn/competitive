#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = LONG_LONG_MAX;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;

    ll r = INF;
    for (int i = 0; i < y; i++) {
      for (int j = 0; j < q; j++) {
        auto t = crt({x + i, p + j}, {2 * (x + y), p + q});
        if (t.first != 0) r = min(r, t.first);
      }
    }
    if (r == INF) {
      cout << "infinity" << endl;
    } else {
      cout << r << endl;
    }
  }
}
