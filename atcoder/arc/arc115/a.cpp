#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;

  ll r = n * (n - 1) / 2;
  vector<ll> v(2);
  for (int i = 0; i < n; i++) {
    bitset<20> b;
    cin >> b;
    r -= v[b.count() % 2];
    v[b.count() % 2]++;
  }
  cout << r << endl;
}
