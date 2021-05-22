#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  ll k;
  cin >> a >> b >> k;
  k--;

  vector c(a + b + 1, vector<ll>(a + b + 1));
  for (int i = 0; i < c.size(); i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }

  string r(a + b, '.');
  for (auto& e : r) {
    ll t = c[a + b - 1][b];
    if (k < t) {
      e = 'a';
    } else {
      k -= t;
      e = 'b';
    }
    (e == 'a' ? a : b)--;
  }
  cout << r << endl;
}
