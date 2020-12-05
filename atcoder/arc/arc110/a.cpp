#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll r = 1;
  for (ll i = 2; i <= n; i++) r *= i / gcd(r, i);
  r++;
  cout << r << endl;
}
