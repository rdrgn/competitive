#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

int main() {
  int n;
  cin >> n;

  int r = INF;
  while (n--) {
    int a, p, x;
    cin >> a >> p >> x;
    if (a < x) r = min(r, p);
  }
  cout << (r == INF ? -1 : r) << endl;
}
