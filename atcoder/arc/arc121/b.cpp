#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<ll>> v(3);
  for (int i = 0; i < 2 * n; i++) {
    ll e;
    char c;
    cin >> e >> c;
    if (c == 'R') v[0].push_back(e);
    if (c == 'G') v[1].push_back(e);
    if (c == 'B') v[2].push_back(e);
  }

  for (const auto& e : v) cerr << e.size() << ' ';
  cerr << endl;

  if (v[0].size() % 2 == 0 && v[1].size() % 2 == 0 && v[2].size() % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<ll> ve;
  vector<vector<ll>> vo;
  for (int i = 0; i < v.size(); i++) {
    sort(v[i].begin(), v[i].end());
    if (v[i].size() % 2 == 0) {
      ve = v[i];
    } else {
      vo.push_back(v[i]);
    }
  }

  ll r = 1e18;
  for (int i = 0, j = 0; i < vo[0].size() && j < vo[1].size();) {
    ll ei = vo[0][i], ej = vo[1][j];
    r = min(r, abs(ei - ej));
    (ei < ej ? i : j)++;
  }

  for (int k = 0; k < 2; k++) {
    ll r0 = 1e18, r1 = 1e18;
    int used_i = 0;
    for (int i = 0, j = 0; i < ve.size() && j < vo[k].size();) {
      ll ei = ve[i], ej = vo[k][j];
      if (abs(ei - ej) < r0) {
        r0 = abs(ei - ej);
        used_i = i;
      }
      (ei < ej ? i : j)++;
    }
    for (int i = 0, j = 0; i < ve.size() && j < vo[1 - k].size();) {
      ll ei = ve[i], ej = vo[1 - k][j];
      r1 = min(r1, abs(ei - ej));
      (ei < ej ? i : j)++;
      if (i == used_i) i++;
    }
    r = min(r, r0 + r1);
  }

  cout << r << endl;
}
