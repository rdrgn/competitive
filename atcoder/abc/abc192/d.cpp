#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string x;
  ll m;
  cin >> x >> m;

  if (x.size() == 1 && (x[0] - '0') <= m) {
    cout << 1 << endl;
    return 0;
  }

  int d = *max_element(x.begin(), x.end()) - '0';

  ll bot = 0, top = m + 1;
  while (bot + 1 < top) {
    auto mid = bot + (top - bot) / 2;
    __int128_t s = 0;
    for (auto it = x.begin(); it != x.end() && s <= m; it++) {
      s = mid * s + (*it - '0');
    }
    if (s <= m) {
      bot = mid;
    } else {
      top = mid;
    }
  }
  cout << max(0ll, bot - d) << endl;
}
