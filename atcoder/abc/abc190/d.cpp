#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  set<pair<ll, ll>> r;
  for (ll i = 1, s = 0; s <= n; s += i, i++) {
    if ((n - s) % i == 0) {
      auto a = (n - s) / i;
      r.insert({a, a + i});
      r.insert({-(a - 1), a + i});
    }
  }
  cout << r.size() << endl;
}
