#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

using S = int;

S op(S a, S b) { return a ^ b; }

S e() { return 0; }

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  segtree<S, op, e> seg(a);

  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      seg.set(x - 1, seg.get(x - 1) ^ y);
    } else if (t == 2) {
      cout << seg.prod(x - 1, y) << endl;
    }
  }
}
