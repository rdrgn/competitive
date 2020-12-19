#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;

void solve() {
  ll n, s, k;
  cin >> n >> s >> k;

  auto p = crt({n - s, 0}, {n, k});

  if (p.first == 0 && p.second == 0) {
    cout << -1 << endl;
    return;
  }

  cout << p.first / k << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
