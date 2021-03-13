#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  int r1 = (w - 1) / b + 1;
  int r2 = w / a;
  if (r1 > r2) {
    cout << "UNSATISFIABLE" << endl;
  } else {
    cout << r1 << ' ' << r2 << endl;
  }
}
