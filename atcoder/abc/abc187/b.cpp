#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;

  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (abs(a[i].first - a[j].first) >= abs(a[i].second - a[j].second)) r++;
    }
  }
  cout << r << endl;
}
