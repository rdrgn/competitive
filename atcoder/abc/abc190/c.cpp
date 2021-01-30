#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (auto& e : a) cin >> e.first >> e.second;
  cin >> k;
  vector<pair<int, int>> c(k);
  for (auto& e : c) cin >> e.first >> e.second;

  int r = 0;
  for (int b = 0; b < (1 << k); b++) {
    int rb = 0;
    vector<bool> v(n + 1);
    for (int i = 0; i < k; i++) v[(b >> i & 1) ? c[i].first : c[i].second] = true;
    for (auto e : a) {
      if (v[e.first] && v[e.second]) rb++;
    }
    r = max(r, rb);
  }
  cout << r << endl;
}
