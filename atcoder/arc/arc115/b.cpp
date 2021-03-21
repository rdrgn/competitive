#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector c(n, vector<ll>(n));
  for (auto& e : c) {
    for (auto& e : e) cin >> e;
  }

  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    a[i] = c[i][0] - c[0][0];
    b[i] = c[0][i] - c[0][0];
  }

  int mi = min_element(a.begin(), a.end()) - a.begin();
  int mj = min_element(b.begin(), b.end()) - b.begin();
  auto ma = a[mi], mb = b[mj], d = c[mi][mj];
  for (int i = 0; i < n; i++) {
    a[i] += -ma;
    b[i] += -mb + d;
  }

  bool r = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) r = r && c[i][j] == a[i] + b[j];
  }

  if (r) {
    cout << "Yes" << endl;
    for (auto e : a) cout << e << ' ';
    cout << endl;
    for (auto e : b) cout << e << ' ';
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}
