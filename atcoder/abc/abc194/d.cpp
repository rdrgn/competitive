#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  double r = 0;
  for (int i = 1; i < n; i++) r += (double)n / (n - i);
  cout << fixed << setprecision(6);
  cout << r << endl;
}
