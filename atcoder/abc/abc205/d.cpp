#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; i++) cin >> a[i + 1];

  while (q--) {
    ll k;
    cin >> k;

    int bot = 0, top = n + 1, mid;
    while (bot + 1 < top) {
      mid = bot + (top - bot) / 2;
      if (a[mid] - mid < k) {
        bot = mid;
      } else {
        top = mid;
      }
    }
    cout << k + bot << endl;
  }
}
