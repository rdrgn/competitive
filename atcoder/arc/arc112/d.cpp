#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& e : s) cin >> e;
  s[0][0] = s[0][w - 1] = s[h - 1][0] = s[h - 1][w - 1] = '#';

  auto to_index = [w](int i, int j) { return i * w + j; };

  int m = 0;
  vector<vector<int>> gi(h), gj(w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != '#') continue;
      m++;
      gi[i].push_back(j);
      gj[j].push_back(i);
    }
  }

  dsu d(h * w);
  int ci = 0, cj = 0;
  for (int i = 0; i < h; i++) {
    for (int k = 1; k < gi[i].size(); k++) d.merge(to_index(i, gi[i][0]), to_index(i, gi[i][k]));
    if (gi[i].empty()) ci++;
  }
  for (int j = 0; j < w; j++) {
    for (int k = 1; k < gj[j].size(); k++) d.merge(to_index(gj[j][0], j), to_index(gj[j][k], j));
    if (gj[j].empty()) cj++;
  }

  cout << d.groups().size() - (h * w - m) - 1 + min(ci, cj) << endl;
}
