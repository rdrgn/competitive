#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (auto& e : a) cin >> e;

  vector memo(h, vector<int>(w, INF));
  auto f = [&](auto&& f, int i, int j) -> int {
    if (memo[i][j] != INF) return memo[i][j];
    if (i == h - 1 && j == w - 1) return memo[i][j] = 0;

    int t = (i + j) % 2;
    int r = -1e9;
    if (i + 1 < h) r = max(r, -f(f, i + 1, j) + (a[i + 1][j] == '+' ? 1 : -1));
    if (j + 1 < w) r = max(r, -f(f, i, j + 1) + (a[i][j + 1] == '+' ? 1 : -1));
    return memo[i][j] = r;
  };

  int r = f(f, 0, 0);

  // for (const auto& e : memo) {
  //   for (auto e : e) cerr << e << ' ';
  //   cerr << endl;
  // }

  if (r > 0) {
    cout << "Takahashi" << endl;
  } else if (r < 0) {
    cout << "Aoki" << endl;
  } else {
    cout << "Draw" << endl;
  }
}
