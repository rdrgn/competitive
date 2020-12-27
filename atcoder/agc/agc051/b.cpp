#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5, X = 1e9;

int main() {
  set<pair<int, int>> r;
  set<int> a, b, c, d;

  auto create = [&](int x, int y) {
    r.insert({x, y});
    a.insert(y);
    b.insert(x + y);
    c.insert(x);
    d.insert(x - y);
  };

  create(0, 0);
  while (r.size() <= N && d.size() < 10 * max({a.size(), b.size(), c.size()})) {
    auto t = r;
    int w = *a.rbegin() + 1;
    for (auto e : t) {
      create(e.first + 2 * w, e.second);
      create(e.first, e.second + 2 * w);
    }
  }

  if (d.size() < 10 * max({a.size(), b.size(), c.size()})) return 1;

  cout << r.size() << endl;
  for (auto e : r) cout << e.first << ' ' << X - e.second << endl;
}
