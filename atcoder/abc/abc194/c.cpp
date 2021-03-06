#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& e : a) cin >> e;

  map<ll, ll> m;
  for (auto e : a) m[e]++;

  ll r = 0;
  for (auto q : m) {
    for (auto p : m) {
      if (q.first <= p.first) break;
      auto d = q.first - p.first;
      r += d * d * p.second * q.second;
    }
  }
  cout << r << endl;
}
