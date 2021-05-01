#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  double D, H;
  cin >> n >> D >> H;
  double r = 0;
  while (n--) {
    double d, h;
    cin >> d >> h;
    r = max(r, (D * h - d * H) / (D - d));
  }
  cout << fixed << setprecision(4);
  cout << r << endl;
}
