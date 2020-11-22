#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

const int di[] = {0, -1, 0, 1};
const int dj[] = {-1, 0, 1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (auto& e : a) cin >> e;

  int si, sj, gi, gj;
  vector<vector<pair<int, int>>> t('z' - 'a' + 1);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == 'S') {
        si = i, sj = j;
      } else if (a[i][j] == 'G') {
        gi = i, gj = j;
      } else if ('a' <= a[i][j] && a[i][j] <= 'z') {
        t[a[i][j] - 'a'].push_back({i, j});
      }
    }
  }

  vector d(h, vector<int>(w, INF));
  queue<pair<int, int>> q;

  d[si][sj] = 0;
  q.push({si, sj});
  while (!q.empty() && d[gi][gj] == INF) {
    int i = q.front().first, j = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++) {
      int i2 = i + di[k], j2 = j + dj[k];
      if (unsigned(i2) >= h || unsigned(j2) >= w) continue;
      if (a[i2][j2] == '#') continue;
      if (d[i][j] + 1 >= d[i2][j2]) continue;
      d[i2][j2] = d[i][j] + 1;
      q.push({i2, j2});
    }
    if ('a' <= a[i][j] && a[i][j] <= 'z') {
      for (auto e : t[a[i][j] - 'a']) {
        int i2 = e.first, j2 = e.second;
        if (d[i][j] + 1 >= d[i2][j2]) continue;
        d[i2][j2] = d[i][j] + 1;
        q.push({i2, j2});
      }
    }
  }
  cout << (d[gi][gj] == INF ? -1 : d[gi][gj]) << endl;
}
