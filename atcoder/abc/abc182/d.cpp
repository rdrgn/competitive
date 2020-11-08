#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), m(n);
  for (auto& e : a) cin >> e;

  m[0] = max(0ll, a[0]);
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
    m[i] = max(m[i - 1], a[i]);
  }

  ll r = 0, s = 0;
  for (int i = 0; i < n; i++) {
    r = max(r, s + m[i]);
    s += a[i];
  }
  cout << r << endl;
}
