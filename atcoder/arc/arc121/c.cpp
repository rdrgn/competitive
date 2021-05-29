#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e, e--;

  auto t = a;

  vector<int> r;
  auto f = [&](int i) {
    r.push_back(i);
    swap(a[i], a[i + 1]);
  };
  for (int i = 0; i < n - 1; i++) {
    int p = find(a.begin(), a.end(), i) - a.begin();
    if (p == i) continue;

    bool b = true;
    int s = r.size() % 2;
    if ((p - 1) % 2 != s) {
      if (p + 3 < n) {
        f(p + 2);
      } else if (p + 1 < n) {
        f(p);
        f(p - 1);
        f(p);
      } else if (i <= p - 2) {
        f(p - 2);
      } else {
        f(p - 2);
        f(p - 1);
        f(p - 2);
        f(p - 1);
        f(p - 2);
        b = false;
      }
    }
    for (int j = p - 1; b && j >= i; j--) {
      f(j);
    }
  }

  bool valid = r.size() <= n * n;
  for (int i = 0; i < r.size() && valid; i++) {
    valid = valid && i % 2 == r[i] % 2;
    swap(t[r[i]], t[r[i] + 1]);
  }
  valid = valid && is_sorted(t.begin(), t.end());
  if (!valid) exit(1);

  cout << r.size() << endl;
  for (auto e : r) cout << e + 1 << ' ';
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
