#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n, m;
  cin >> n >> m;

  auto dfs = [&](auto&& dfs, int i, int e0, int ec, int p, mint w) -> mint {
    mint r = w * (m / p);
    for (int e = e0; e <= m / p; e++, ec = 0) {
      r += dfs(dfs, i + 1, e, ec + 1, p * e, w * (n - 1 - i) / (ec + 1));
    }
    return r;
  };
  cout << dfs(dfs, 0, 2, 0, 1, 1).val() << endl;
}
