#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll r = 1e18;
  for (int b = 0; (1ll << b) <= n; b++) {
    ll a = n >> b;
    ll c = n - (a << b);
    r = min(r, a + b + c);
  }
  cout << r << endl;
}
