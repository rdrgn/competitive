#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll r = 0;
  for (ll p = 10; (p + 1) * r <= n;) {
    r++;
    if (r >= p) p *= 10;
  }
  r--;
  cout << r << endl;
}
