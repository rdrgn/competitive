#include <bits/stdc++.h>
using namespace std;

template <class T>
void set_if_less(T& a, T b) {
  if (a > b) a = b;
}

int main() {
  int k;
  string s;
  cin >> k >> s;

  // if (k == 0) {
  //   auto rs = s;
  //   reverse(rs.begin(), rs.end());
  //   cout << (s == rs ? 1 : 0) << endl;
  //   return 0;
  // }

  bool possible = false;
  vector<vector<char>> c(k), d;
  auto f = [&](auto&& f, int a, int b, int l) -> void {
    if (l == k) {
      if (abs(b - a) != 1) possible = true;

      if (a == b) return;

      if (d.size() < abs(b - a)) d.resize(abs(b - a));
      for (int i = 0, u = (b - a) / abs(b - a); a + i * u != b; i++) {
        d[i].push_back(s[a + i * u]);
      }
      return;
    }

    if (a < b) {
      int n = b - a;
      if (n % 2) c[l].push_back(s[a + n / 2]);
      f(f, a, a + n / 2, l + 1);
      f(f, b - 1, b - 1 - n / 2, l + 1);
    } else if (b < a) {
      int n = a - b;
      if (n % 2) c[l].push_back(s[a - n / 2]);
      f(f, a, a - n / 2, l + 1);
      f(f, b + 1, b + 1 + n / 2, l + 1);
    }
  };
  f(f, 0, s.size(), 0);

  if (!possible) {
    cout << "impossible" << endl;
    return 0;
  }

  int r = 0;
  for (int i = 0; i < c.size(); i++) {
    // cerr << i << ' ';
    // for (auto e : c[i]) cerr << e;
    // cerr << endl;

    int t = 0;
    map<char, int> m;
    for (auto e : c[i]) {
      m[e]++;
      t = max(t, m[e]);
    }

    r += c[i].size() - t;
  }
  if (d.size()) {
    vector dp(d.size() / 2 + 1, vector<int>(2, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < d.size() / 2; i++) {
      // cerr << i << ' ';
      // for (auto e : d[i]) cerr << e;
      // cerr << ' ';
      // for (auto e : d[d.size() - 1 - i]) cerr << e;
      // cerr << endl;

      map<char, int> m1, m2;
      for (char e = 'a'; e <= 'z'; e++) m1[e] = 0, m2[e] = 0;
      for (auto e : d[i]) m1[e]++;
      for (auto e : d[d.size() - 1 - i]) m2[e]++;

      int n = d[i].size();
      int t0 = 1e9, t1 = 1e9;
      for (const auto e1 : m1) {
        for (const auto e2 : m2) {
          t0 = min(t0, (n - e1.second) + (n - e2.second));
          if (e1.first != e2.first) t1 = min(t1, (n - e1.second) + (n - e2.second));
        }
      }
      set_if_less(dp[i + 1][0], dp[i][0] + t0);
      set_if_less(dp[i + 1][1], dp[i][1] + t0);
      set_if_less(dp[i + 1][1], dp[i][0] + t1);
    }
    r += dp[d.size() / 2][1];
  }
  if (d.size() % 2) {
    int i = d.size() / 2;

    int t = 0;
    map<char, int> m;
    for (auto e : d[i]) {
      m[e]++;
      t = max(t, m[e]);
    }

    r += d[i].size() - t;
  }
  cout << r << endl;
}
