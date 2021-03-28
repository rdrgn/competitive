#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;
  sort(a.begin(), a.end());

  mint r = 0, s = 0;
  for (auto e : a) {
    r += s * e + (mint)e * e;
    s = 2 * s + e;
  }
  cout << r.val() << endl;
}
