#include <bits/stdc++.h>
using namespace std;

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double dx = x2 - x1, dy = y1 + y2;
  cout << fixed << setprecision(6);
  cout << x1 + dx * (y1 / dy) << endl;
}
