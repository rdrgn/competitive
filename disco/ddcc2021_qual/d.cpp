#include <bits/stdc++.h>
using namespace std;

using I = vector<vector<int>>;
using O = int;

O solve(const I& input) {
  int n = 10;
  auto a = input[0], b = input[1];

  vector m(1 << n, vector<int>(200, -1));
  auto dfs = [&](auto&& dfs, int s, int p, int l) -> int {
    if (m[s][l] != -1) return m[s][l];
    // cerr << bitset<10>(s) << ' ' << p << endl;

    int r = p + l;
    for (int i = 0; i < n; i++) {
      int s2 = s, p2 = p, l2 = l;
      if (!(s2 >> i & 1)) continue;
      if (l2 < a[i]) continue;
      l2 -= a[i];
      bool e = l2 == 0;
      if (e) l2 += b[i];
      p2 += b[i];
      s2 ^= 1 << i;
      if (i - 2 >= 0 && !(s2 >> i - 2 & 1) && (s2 >> i - 1 & 1)) {
        if (e) l2 += b[i - 1];
        p2 += b[i - 1];
        s2 ^= 1 << i - 1;
      }
      if (i + 2 < n && !(s2 >> i + 2 & 1) && (s2 >> i + 1 & 1)) {
        if (e) l2 += b[i + 1];
        p2 += b[i + 1];
        s2 ^= 1 << i + 1;
      }
      r = max(r, dfs(dfs, s2, p2, l2));
    }
    return m[s][l] = r;
  };
  return dfs(dfs, (1 << n) - 1, 0, 10);
}

int main() {
  vector<O> r;

  // r.push_back(solve({{7, 1, 3, 2, 5, 3, 4, 5, 1, 6}, {12, 10, 6, 5, 18, 16, 8, 7, 15, 12}}));
  // r.push_back(solve({{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}}));
  // r.push_back(solve({{11, 8, 2, 10, 6, 8, 2, 13, 3, 9}, {12, 1, 3, 6, 2, 1, 9, 13, 10, 4}}));

  r.push_back(solve({{6, 3, 4, 5, 8, 5, 9, 3, 1, 7}, {5, 10, 6, 4, 9, 1, 7, 8, 4, 3}}));
  r.push_back(solve({{10, 7, 5, 7, 3, 2, 4, 4, 3, 8}, {8, 1, 5, 6, 9, 8, 8, 4, 1, 3}}));
  r.push_back(solve({{12, 7, 6, 4, 6, 11, 2, 9, 2, 15}, {2, 6, 10, 1, 8, 4, 2, 2, 9, 5}}));

  for (int i = 0; i < r.size(); i++) cout << r[i] << "\n,"[i < r.size() - 1];
}
