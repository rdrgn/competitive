#include <bits/stdc++.h>
using namespace std;

int main() {
  constexpr int M = 5, T = 3;
  int n;
  cin >> n;
  vector a(n, vector<int>(M));
  for (auto& e : a) {
    for (auto& e : e) cin >> e;
  }

  int bot = 1, top = 1e9 + 1, mid;
  while (bot + 1 < top) {
    mid = bot + (top - bot) / 2;
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < M; j++) {
        if (a[i][j] >= mid) g[i] |= 1 << j;
      }
    }
    vector dp(T + 1, vector<int>(1 << M));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = T - 1; j >= 0; j--) {
        for (int k = 0; k < (1 << M); k++) {
          dp[j + 1][k | g[i]] |= dp[j][k];
        }
      }
    }
    if (dp[T][(1 << M) - 1]) {
      bot = mid;
    } else {
      top = mid;
    }
  }
  cout << bot << endl;
}
