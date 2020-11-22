#include <bits/stdc++.h>
using namespace std;

int main() {
  constexpr double INF = 1e9;
  constexpr int M = 100;
  int a, b, c;
  cin >> a >> b >> c;

  vector memo(M + 1, vector(M + 1, vector<double>(M + 1, INF)));
  auto dfs = [&](auto &&dfs, int a, int b, int c) -> double {
    if (a >= M || b >= M || c >= M) return 0;
    if (memo[a][b][c] != INF) return memo[a][b][c];
    double r = 1;
    int s = a + b + c;
    r += dfs(dfs, a + 1, b, c) * a / s;
    r += dfs(dfs, a, b + 1, c) * b / s;
    r += dfs(dfs, a, b, c + 1) * c / s;
    return memo[a][b][c] = r;
  };
  cout << fixed << setprecision(6);
  cout << dfs(dfs, a, b, c) << endl;
}
