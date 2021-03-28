#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  int r = 0;
  for (int i = 0; i < n - 1; i++) {
    auto j = min_element(a.begin() + i, a.end()) - a.begin();
    reverse(a.begin() + i, a.begin() + j + 1);
    r += j - i + 1;
  }
  cout << r << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
