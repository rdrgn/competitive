#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> x(n);
  for (auto& e : x) cin >> e;

  vector<ll> p;
  {
    vector<bool> v(50 + 1, true);
    for (ll i = 2; i <= 50; i++) {
      if (!v[i]) continue;
      p.push_back(i);
      for (ll j = 2 * i; j <= 50; j += i) v[j] = false;
    }
  }

  ll r = 1e18;
  for (int s = 1; s < (1 << p.size()); s++) {
    ll y = 1;
    for (int i = 0; i < p.size(); i++) {
      if (s >> i & 1) y *= p[i];
    }
    bool b = true;
    for (auto e : x) b = b && gcd(y, e) != 1;
    if (b) r = min(r, y);
  }
  cout << r << endl;
}
