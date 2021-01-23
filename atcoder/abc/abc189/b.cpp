#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  x *= 100;

  int r = -1;
  for (int i = 0; i < n; i++) {
    int v, p;
    cin >> v >> p;
    if (r != -1) continue;
    x -= v * p;
    if (x < 0) r = i + 1;
  }
  cout << r << endl;
}
