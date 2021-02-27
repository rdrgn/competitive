#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  set<ll> s;
  for (ll i = 2; i <= n / i; i++) {
    for (ll d = i * i; d <= n; d *= i) {
      s.insert(d);
    }
  }
  cout << n - s.size() << endl;
}
