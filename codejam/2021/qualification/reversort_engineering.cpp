#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, c;
  cin >> n >> c;

  if (c < n - 1 || n * (n + 1) / 2 - 1 < c) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  c -= n - 1;
  vector<int> v(n - 1, 1);
  for (int i = 0; i < n - 1; i++) {
    auto t = min(c, n - i - 1);
    c -= t;
    v[i] += t;
  }

  vector<int> r(n);
  iota(r.begin(), r.end(), 1);
  for (int i = n - 2; i >= 0; i--) reverse(r.begin() + i, r.begin() + i + v[i]);

  for (auto e : r) cout << e << ' ';
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
