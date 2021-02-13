#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll b, c;
  cin >> b >> c;

  set<pair<ll, ll>> s;
  s.insert({b - c / 2, b});
  s.insert({-b - (c - 1) / 2, -b});
  s.insert({-b, -(b - (c - 1) / 2)});
  s.insert({-(-b), -(-b - (c - 2) / 2)});

  ll r = 0, t = -2e18;
  for (auto e : s) {
    if (e.first <= t) {
      r += max(0ll, e.second - t);
    } else {
      r += e.second - e.first + 1;
    }
    t = max(t, e.second);
  }
  cout << r << endl;
}
