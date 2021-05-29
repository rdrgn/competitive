#include <bits/stdc++.h>
using namespace std;

int d(pair<int, int> a, pair<int, int> b) { return max(abs(a.first - b.first), abs(a.second - b.second)); }

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;

  vector<int> u(n), v(n);
  iota(u.begin(), u.end(), 0);
  iota(v.begin(), v.end(), 0);
  sort(u.begin(), u.end(), [&](int i, int j) { return a[i].first < a[j].first; });
  sort(v.begin(), v.end(), [&](int i, int j) { return a[i].second < a[j].second; });

  set<pair<int, int>> s;
  for (int i = 0; i < 2; i++) {
    for (int j = n - 2; j < n; j++) {
      if (i == j) continue;
      s.insert(minmax(u[i], u[j]));
      s.insert(minmax(v[i], v[j]));
    }
  }

  vector<int> r;
  for (auto e : s) r.push_back(d(a[e.first], a[e.second]));
  sort(r.rbegin(), r.rend());

  // for (auto e : r) cerr << e << ' ';
  // cerr << endl;

  cout << r[1] << endl;
}
