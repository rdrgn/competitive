#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  ll r = 0, d = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && t[i] == '1') {
      d++;
    } else if (s[i] == '1' && t[i] == '0') {
      if (d > 0) {
        d--;
      } else {
        d++;
      }
    }
    r += d;
  }
  cout << (d == 0 ? r : -1) << endl;
}
