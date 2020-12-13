#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, t;
  cin >> n >> m >> t;

  bool r = true;
  int x = 0, y = n;
  while (m--) {
    int a, b;
    cin >> a >> b;

    y = max(0, y - (a - x));
    if (y == 0) r = false;

    y = min(n, y + (b - a));
    x = b;
  }
  y = max(0, y - (t - x));
  if (y == 0) r = false;

  cout << (r ? "Yes" : "No") << endl;
}
