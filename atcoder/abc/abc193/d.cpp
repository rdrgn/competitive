#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int k;
  string s, t;
  cin >> k >> s >> t;
  s.pop_back();
  t.pop_back();

  vector<int> c(10, k), a(10), b(10);
  for (auto e : s) c[e - '0']--, a[e - '0']++;
  for (auto e : t) c[e - '0']--, b[e - '0']++;

  vector<ll> d(10);
  d[0] = 1;
  for (int i = 1; i <= 9; i++) d[i] = d[i - 1] * 10;

  double r = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i == j) {
        if (c[i] < 2) continue;
      } else {
        if (c[i] < 1 || c[j] < 1) continue;
      }

      a[i]++, b[j]++;
      ll p = 0, q = 0;
      for (int k = 1; k <= 9; k++) {
        p += k * d[a[k]];
        q += k * d[b[k]];
      }
      if (p > q) {
        if (i == j) {
          r += ((double)c[i] / (9 * k - 8)) * ((double)(c[i] - 1) / (9 * k - 9));
        } else {
          r += ((double)c[i] / (9 * k - 8)) * ((double)c[j] / (9 * k - 9));
        }
      }
      a[i]--, b[j]--;
    }
  }
  cout << fixed << setprecision(6);
  cout << r << endl;
}
