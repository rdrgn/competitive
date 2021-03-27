#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int main() {
  int n, m;
  cin >> n >> m;
  vector g(n, vector<vector<int>>(26));
  while (m--) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    a--, b--;
    g[a][c - 'a'].push_back(b);
    g[b][c - 'a'].push_back(a);
  }

  int r = INF;

  struct state {
    int i, j, r;
  };
  vector v(n, vector<bool>(n));
  queue<state> q;
  q.push({0, n - 1, 0});
  while (!q.empty()) {
    auto e = q.front();
    q.pop();
    if (v[e.i][e.j]) continue;
    v[e.i][e.j] = true;
    for (int c = 0; c < 26; c++) {
      for (auto i2 : g[e.i][c]) {
        for (auto j2 : g[e.j][c]) {
          if (i2 == e.j && j2 == e.i) {
            r = min(r, e.r + 1);
            continue;
          }
          if (i2 == j2) {
            r = min(r, e.r + 2);
            continue;
          }
          q.push({i2, j2, e.r + 2});
        }
      }
    }
    if (r != INF) break;
  }

  cout << (r == INF ? -1 : r) << endl;
}
