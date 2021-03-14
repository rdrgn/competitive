#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n;
  cin >> n;
  vector<int> f(n);
  for (auto& e : f) {
    cin >> e;
    e--;
  }

  dsu d(n);
  for (int i = 0; i < n; i++) d.merge(i, f[i]);

  mint r = 1;
  for (int i = d.groups().size(); i; i--) r *= 2;
  r -= 1;
  cout << r.val() << endl;
}
