#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  auto s = a;
  sort(s.begin(), s.end());

  for (auto e : a) cout << k / n + (e < s[k % n] ? 1 : 0) << endl;
}
