#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, p;
  cin >> n >> p;

  map<int, ll> m;
  while (n--) {
    ll a, b, c;
    cin >> a >> b >> c;
    m[a - 1] += c;
    m[b] -= c;
  }

  ll i = 0, s = 0, r = 0;
  for (const auto [j, d] : m) {
    r += (j - i) * min(s, p);
    i = j;
    s += d;
  }
  cout << r << endl;
}
