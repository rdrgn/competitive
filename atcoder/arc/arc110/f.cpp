#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  if (n == 2) {
    if (a[0] == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
      cout << 0 << endl;
    }
    return 0;
  }

  int p1, p2;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) p1 = i;
    if (a[i] == 2) p2 = i;
  }

  vector<int> r;
  auto esoswap = [&](int i) {
    int i2 = (i + a[i]) % n;
    swap(a[i], a[i2]);
    r.push_back(i);
    if (a[i] == 1) p1 = i;
    if (a[i] == 2) p2 = i;
    if (a[i2] == 1) p1 = i2;
    if (a[i2] == 2) p2 = i2;
  };

  while ((p1 + 1) % n != p2) esoswap(p1);

  for (int _ = 0; _ < n * n; _++) {
    if (a[(p2 + 1) % n] < a[(p2 + 2) % n] || a[(p2 + 2) % n] == 0) {
      esoswap(p1);
      esoswap(p2);
    } else {
      esoswap(p2);
      esoswap(p1);
      esoswap(p1);
    }

    bool b = true;
    for (int i = 0; i < n; i++) b = b && (a[i] + 1) % n == a[(i + 1) % n];
    if (b) break;
  }

  while (p1 != 1 || p2 != 2) esoswap(p1);

  if (is_sorted(a.begin(), a.end())) {
    cout << r.size() << endl;
    for (auto e : r) cout << e << endl;
  } else {
    // assert(false);
    cout << -1 << endl;
  }
}
