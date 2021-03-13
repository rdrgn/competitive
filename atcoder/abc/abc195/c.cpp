#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll r = 0;
  for (ll d = 1000; d <= n; d *= 1000) r += n - d + 1;
  cout << r << endl;
}
