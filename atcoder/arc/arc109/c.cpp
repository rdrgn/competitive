#include <bits/stdc++.h>
using namespace std;

char judge(char a, char b) {
  if (a == 'R') return b == 'S' ? a : b;
  if (a == 'P') return b == 'R' ? a : b;
  if (a == 'S') return b == 'P' ? a : b;
  return a;
}

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  if (n == 1) {
    cout << s[0] << endl;
    return 0;
  }

  vector<int> p(k + 1);
  p[0] = 1;
  for (int i = 0; i < n; i++) p[i + 1] = p[i] * 2 % n;

  vector memo(n, vector<char>(k + 1, '.'));
  auto f = [&](auto&& f, int h, int x) -> char {
    if (memo[h][x] != '.') return memo[h][x];
    char r;
    if (x == 0) {
      r = s[h];
    } else if (x == 1) {
      r = judge(s[h], s[(h + 1) % n]);
    } else {
      r = judge(f(f, h, x - 1), f(f, (h + p[x - 1]) % n, x - 1));
    }
    return memo[h][x] = r;
  };

  cout << f(f, 0, k) << endl;
}
