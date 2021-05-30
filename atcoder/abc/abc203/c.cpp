#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<pair<ll, ll>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;
  sort(a.begin(), a.end());

  ll r = 0;
  for (auto e : a) {
    if (k < e.first - r) {
      r += k;
      k = 0;
      break;
    }
    k -= e.first - r;
    k += e.second;
    r = e.first;
  }
  r += k;
  cout << r << endl;
}
