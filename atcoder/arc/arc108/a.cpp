#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll s, p;
  cin >> s >> p;

  bool r = false;
  for (ll i = 1; !r && i * i <= p; i++) {
    if (p % i) continue;
    if (i + p / i == s) r = true;
  }
  cout << (r ? "Yes" : "No") << endl;
}
