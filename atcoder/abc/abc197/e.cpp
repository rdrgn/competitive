#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
void set_if_less(T& a, T b) {
  if (a > b) a = b;
}

int main() {
  int n;
  cin >> n;
  vector<pair<ll, int>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;

  int m = 0;
  {
    map<int, int> c;
    for (auto e : a) c[e.second];
    for (auto& e : c) {
      e.second = m;
      m++;
    }
    for (auto& e : a) e.second = c[e.second];
  }

  vector<vector<ll>> b(m);
  for (auto e : a) b[e.second].push_back(e.first);
  vector<pair<ll, ll>> v(m);
  for (int i = 0; i < m; i++) {
    auto it = minmax_element(b[i].begin(), b[i].end());
    v[i] = {*it.first, *it.second};
  }

  vector dp(m, vector<ll>(2, 1e18));
  dp[0][0] = abs(v[0].second) + (v[0].second - v[0].first);
  dp[0][1] = abs(v[0].first) + (v[0].second - v[0].first);
  for (int i = 0; i + 1 < m; i++) {
    auto w = v[i + 1].second - v[i + 1].first;
    set_if_less(dp[i + 1][0], dp[i][0] + (abs(v[i + 1].second - v[i].first) + w));
    set_if_less(dp[i + 1][0], dp[i][1] + (abs(v[i + 1].second - v[i].second) + w));
    set_if_less(dp[i + 1][1], dp[i][0] + (abs(v[i + 1].first - v[i].first) + w));
    set_if_less(dp[i + 1][1], dp[i][1] + (abs(v[i + 1].first - v[i].second) + w));
  }
  auto r = min(dp[m - 1][0] + abs(v[m - 1].first), dp[m - 1][1] + abs(v[m - 1].second));
  cout << r << endl;
}
