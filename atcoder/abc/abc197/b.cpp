#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, y, x;
  cin >> h >> w >> y >> x;
  y--, x--;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  int r = 1;
  for (auto d : vector<pair<int, int>>{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}) {
    int i = y, j = x;
    while (true) {
      i += d.first;
      j += d.second;
      if (unsigned(i) >= h) break;
      if (unsigned(j) >= w) break;
      if (s[i][j] == '#') break;
      r++;
    }
  }
  cout << r << endl;
}
