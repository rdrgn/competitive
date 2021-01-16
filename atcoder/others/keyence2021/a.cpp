#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  for (int i = 0; i + 1 < n; i++) a[i + 1] = max(a[i + 1], a[i]);

  ll r = 0;
  for (int i = 0; i < n; i++) cout << (r = max(r, a[i] * b[i])) << endl;
}
