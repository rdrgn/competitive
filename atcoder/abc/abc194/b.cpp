#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;

  int r = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r = min(r, i == j ? a[i].first + a[i].second : max(a[i].first, a[j].second));
    }
  }
  cout << r << endl;
}
