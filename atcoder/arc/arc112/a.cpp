#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll l, r;
    cin >> l >> r;
    ll n = max(0ll, r - 2 * l + 1);
    cout << n * (n + 1) / 2 << endl;
  }
}
