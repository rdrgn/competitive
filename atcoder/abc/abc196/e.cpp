#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<ll, int>> a(n);
  for (auto& e : a) cin >> e.first >> e.second;
  reverse(a.begin(), a.end());

  ll s = 0, bot = -1e18, top = 1e18;
  for (auto e : a) {
    switch (e.second) {
      case 1: {
        s += e.first;
        bot -= e.first;
        top -= e.first;
        break;
      }
      case 2: {
        if (bot == top) break;
        bot = max(bot, e.first);
        bot = min(bot, top);
        break;
      }
      case 3: {
        if (bot == top) break;
        top = min(top, e.first);
        top = max(bot, top);
        break;
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
    cout << max(bot, min(top, x)) + s << endl;
  }
}
