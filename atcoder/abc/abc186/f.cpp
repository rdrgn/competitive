#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;

using S = ll;

S op(S a, S b) { return a + b; }

S e() { return 0; }

int main() {
  ll w, h, m;
  cin >> w >> h >> m;
  vector<vector<int>> a(h);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[y - 1].push_back(x - 1);
  }
  for (auto& e : a) sort(e.begin(), e.end());

  vector<S> v(w);
  if (a[0].size()) fill(v.begin() + a[0][0], v.end(), 1);

  ll r = h * w;
  segtree<S, op, e> seg(v);
  bool b = false;
  for (auto& e : a) {
    for (auto x : e) seg.set(x, 1);
    if (e.size() && e[0] == 0) b = true;
    if (b || e.size()) r -= seg.prod(b ? 0 : e[0], w);
  }
  cout << r << endl;
}
