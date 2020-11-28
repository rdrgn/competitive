#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  cout << x + (a <= b ? b - a : a - b - 1) * min(2 * x, y) << endl;
}
