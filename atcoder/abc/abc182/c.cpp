#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int r = s.size();
  for (int b = 0; b < (1 << s.size()); b++) {
    int t = 0;
    for (int i = 0; i < s.size(); i++) {
      if (!(b >> i & 1)) t += s[i] - '0';
    }
    if (t % 3 == 0) r = min(r, (int)bitset<18>(b).count());
  }
  cout << (r == s.size() ? -1 : r) << endl;
}
