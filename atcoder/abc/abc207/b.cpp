#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  ll t = c * d - b;

  if (t <= 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << (a - 1) / t + 1 << endl;
}
