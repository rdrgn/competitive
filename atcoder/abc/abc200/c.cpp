#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<int, ll> m;
  while (n--) {
    int e;
    cin >> e;
    m[e % 200]++;
  }

  ll r = 0;
  for (auto e : m) r += e.second * (e.second - 1) / 2;
  cout << r << endl;
}
