#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> r(n);
  r[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      if (r[i - 1] + 1 > r[j - 1]) r[j - 1] = r[i - 1] + 1;
    }
  }
  for (auto e : r) cout << e << ' ';
  cout << endl;
}
