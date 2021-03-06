#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  vector<int> v(n + 1), t(n + 1, -1);
  for (int i = 0; i < n; i++) {
    v[a[i]] = max(v[a[i]], i - t[a[i]] - 1);
    t[a[i]] = i;
  }
  for (int i = 0; i < n + 1; i++) {
    v[i] = max(v[i], n - t[i] - 1);
  }

  // for (auto e : v) cerr << e << ' ';
  // cerr << endl;

  int r = -1;
  for (int i = 0; i < n + 1; i++) {
    if (m <= v[i]) {
      r = i;
      break;
    }
  }
  cout << r << endl;
}
