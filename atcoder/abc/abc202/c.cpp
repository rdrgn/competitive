#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;
  for (auto& e : c) cin >> e;

  ll r = 0;
  map<int, ll> m;
  for (auto e : c) m[b[e - 1]]++;
  for (auto e : a) r += m[e];
  cout << r << endl;
}
