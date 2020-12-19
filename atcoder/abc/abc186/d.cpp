#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  sort(a.begin(), a.end());

  auto s = a;
  for (int i = 0; i + 1 < n; i++) s[i + 1] += s[i];

  ll r = 0;
  for (int i = 0; i + 1 < n; i++) r += (i + 1) * a[i + 1] - s[i];
  cout << r << endl;
}
