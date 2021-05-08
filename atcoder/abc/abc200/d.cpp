#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  constexpr int M = 200;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  vector<vector<int>> b(2);

  vector<vector<pair<int, int>>> v(M);
  v[0].push_back({-1, -1});
  for (int i = 0; i < n && b[0].empty(); i++) {
    vector<bool> t(M);
    for (int j = 0; j < M; j++) t[j] = !v[j].empty();

    for (int j = 0; j < M; j++) {
      if (!t[j]) continue;

      int j2 = (j + a[i]) % M;
      v[j2].push_back({j, i});

      if (v[j2].size() >= (j2 == 0 ? 3 : 2)) {
        v[0].erase(v[0].begin());
        for (int k = 0; k < 2; k++) {
          b[k].push_back(v[j2][k].second);
          int p = v[j2][k].first;
          while (p != 0) {
            b[k].push_back(v[p][0].second);
            p = v[p][0].first;
          }
          reverse(b[k].begin(), b[k].end());
        }
        break;
      }
    }
  }

  // for (int j = 0; j < M; j++) {
  //   cerr << j << ": ";
  //   for (auto e : v[j]) cerr << "(" << e.first << ", " << e.second << ") ";
  //   cerr << endl;
  // }

  if (b[0].empty()) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  for (const auto& e : b) {
    cout << e.size() << ' ';
    for (auto e : e) cout << e + 1 << ' ';
    cout << endl;
  }
}
