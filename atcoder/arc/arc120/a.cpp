#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  ll s = 0, si = 0, m = 0;
  for (int i = 0; i < n; i++) {
    si += a[i];
    s += si;
    m = max(m, a[i]);
    cout << s + (i + 1) * m << endl;
  }
}
