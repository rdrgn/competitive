#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  bool flipped = false;
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    if (t == 1) {
      if (flipped) {
        swap(s[(a + n) % (2 * n)], s[(b + n) % (2 * n)]);
      } else {
        swap(s[a], s[b]);
      }
    } else if (t == 2) {
      flipped ^= true;
    }
  }
  cout << (flipped ? s.substr(n) + s.substr(0, n) : s) << endl;
}
