#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, t;
  cin >> n >> t;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  int n1 = n / 2, n2 = n - n / 2;
  vector<ll> a1(a.begin(), a.begin() + n1), a2(a.begin() + n1, a.end());

  auto f = [](ll t, const vector<ll>& a) {
    int n = a.size();
    vector<ll> r;
    for (int b = 0; b < (1 << n); b++) {
      ll s = 0;
      for (int i = 0; i < n; i++) {
        if (b >> i & 1) s += a[i];
      }
      if (s <= t) r.push_back(s);
    }
    sort(r.begin(), r.end());
    return r;
  };
  auto r1 = f(t, a1);
  auto r2 = f(t, a2);

  ll r = 0;
  for (int i1 = 0, i2 = r2.size() - 1; i1 < r1.size(); i1++) {
    while (i2 >= 0 && r1[i1] + r2[i2] > t) i2--;
    if (i2 < 0) break;
    r = max(r, r1[i1] + r2[i2]);
  }
  cout << r << endl;
}
