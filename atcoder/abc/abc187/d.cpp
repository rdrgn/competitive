#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> v(n);
  ll t = 0;
  for (auto &e : v) {
    ll a, b;
    cin >> a >> b;
    e = 2 * a + b;
    t += a;
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i + 1 < n; i++) v[i + 1] += v[i];

  cout << upper_bound(v.begin(), v.end(), t) - v.begin() + 1 << endl;
}
