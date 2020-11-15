#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, w;
  cin >> n >> w;
  vector<ll> v(2e5 + 1);
  while (n--) {
    ll s, t, p;
    cin >> s >> t >> p;
    v[s] += p;
    v[t] += -p;
  }
  bool r = true;
  for (int i = 0; i + 1 < v.size(); i++) {
    r = r && v[i] <= w;
    v[i + 1] += v[i];
  }
  cout << (r ? "Yes" : "No") << endl;
}
