#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  int r = 1, rk = a[0];
  for (int k = 2; k <= 1000; k++) {
    int c = 0;
    for (auto e : a) {
      if (e % k == 0) c++;
    }
    if (c > r) {
      r = c;
      rk = k;
    }
  }
  cout << rk << endl;
}
