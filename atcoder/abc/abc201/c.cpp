#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int t = 0, f = 0;
  for (int i = 0; i < 10; i++) {
    if (s[i] == 'o') t |= 1 << i;
    if (s[i] == 'x') f |= 1 << i;
  }

  int r = 0;
  for (int i = 0; i < (int)1e4; i++) {
    int x = i, b = 0;
    for (int j = 0; j < 4; j++, x /= 10) b |= 1 << (x % 10);
    int bi = ((1 << 10) - 1) ^ b;
    if ((b & t) == t && (bi & f) == f) r++;
  }
  cout << r << endl;
}
