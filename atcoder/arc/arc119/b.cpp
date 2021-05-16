#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  int r = 0, d = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && t[i] == '0') {
      if (d != 0) r++;
    } else if (s[i] == '0') {
      d++;
      r++;
    } else if (t[i] == '0') {
      d--;
    }
  }
  cout << (d == 0 ? r : -1) << endl;
}
