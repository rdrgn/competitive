#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll bot = 1, top = n + 1, mid;
  while (bot + 1 < top) {
    mid = (top - bot) / 2 + bot;
    auto t = (__int128_t)mid * (mid + 1) / 2;
    if (t <= n + 1) {
      bot = mid;
    } else {
      top = mid;
    }
  }
  cout << n - bot + 1 << endl;
}
