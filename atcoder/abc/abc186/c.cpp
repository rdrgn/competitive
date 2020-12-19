#include <bits/stdc++.h>
using namespace std;

bool f(int x, int d) {
  while (x) {
    int e = x % d;
    if (e == 7) return false;
    x /= d;
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  int r = 0;
  for (int i = 1; i <= n; i++) {
    if (f(i, 8) && f(i, 10)) r++;
  }
  cout << r << endl;
}
