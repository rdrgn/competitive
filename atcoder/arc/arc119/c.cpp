#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 2);
  for (int i = 2; i < n + 2; i++) cin >> a[i];

  ll r = 0;
  vector<ll> s(n + 2);
  map<ll, ll> m;
  for (int i = 1; i < n + 2; i++) {
    if (i - 2 >= 0) s[i] = s[i - 2] + a[i];

    auto d = s[i] - s[i - 1];
    if (i % 2) d = -d;
    r += m[d];
    m[d]++;
  }

  cout << r << endl;
}
