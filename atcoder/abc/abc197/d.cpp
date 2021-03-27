#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  double x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  complex<double> p1(x1, y1), p2(x2, y2);
  auto o = p1 + (p2 - p1) / 2.0;
  auto v = p1 - o;
  auto r = o + polar(abs(v), arg(v) + (2 * M_PI / n));
  cout << fixed << setprecision(6) << endl;
  cout << r.real() << ' ' << r.imag() << endl;
}
