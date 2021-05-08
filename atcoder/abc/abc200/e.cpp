#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector C(3e6 + 1, vector<ll>(2 + 1));
  for (int i = 0; i < C.size(); i++) {
    C[i][0] = 1;
    if (i < C[i].size()) C[i][i] = 1;
    for (int j = 1; j < min((int)C[i].size(), i); j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }

  ll n, k;
  cin >> n >> k;
  k--;

  ll s = 3;
  for (;; s++) {
    ll t = C[s - 3 + 2][2];
    if (s > n) t -= 3 * C[s - n - 3 + 2][2];
    if (s > 2 * n) t += 3 * C[s - 2 * n - 3 + 2][2];

    if (k < t) break;
    k -= t;
  }
  // cerr << s << ' ' << k << endl;

  ll r1 = 1;
  for (;; r1++) {
    ll t;
    if (s - r1 > 2 * n) {
      t = 0;
    } else if (s - r1 > n) {
      t = 2 * n - (s - r1) + 1;
    } else {
      t = s - r1 - 1;
    }
    if (k < t) break;
    k -= t;
  }

  ll r2 = 1;
  for (;; r2++) {
    ll t;
    if (s - r1 - r2 > n) {
      t = 0;
    } else {
      t = 1;
    }
    if (k < t) break;
    k -= t;
  }

  cout << r1 << ' ' << r2 << ' ' << s - r1 - r2 << endl;
}
