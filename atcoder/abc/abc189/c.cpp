#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i, m = 1e9; j < n; j++) {
      m = min(m, a[j]);
      r = max(r, (j - i + 1) * m);
    }
  }
  cout << r << endl;
}
