#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int x = abs(x2 - x1), y = abs(y2 - y1);
  if (x > y) swap(x, y);

  int r;
  if (x == 0 && y == 0) {
    r = 0;
  } else if (y - x == 0 || x + y <= 3) {
    r = 1;
  } else if ((y - x) % 2 == 0 || y - x <= 3 || x + y <= 6) {
    r = 2;
  } else {
    r = 3;
  }
  cout << r << endl;
}
