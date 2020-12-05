#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) {
    cin >> e;
    e--;
  }

  vector<int> r;
  for (int h = 0; h < n - 1;) {
    int t = find(a.begin() + h + 1, a.end(), h) - a.begin();
    if (t == n) break;
    for (int i = t - 1; i >= h; i--) {
      r.push_back(i);
      swap(a[i], a[i + 1]);
    }
    h = t;
  }

  bool b = true;
  for (int i = 0; i < n; i++) b = b && a[i] == i;

  if (b && r.size() == n - 1) {
    for (auto e : r) cout << e + 1 << endl;
  } else {
    cout << -1 << endl;
  }
}
