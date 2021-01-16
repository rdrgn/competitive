#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> m(n);
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    m[e]++;
  }

  for (int i = 0; i + 1 < n; i++) {
    m[i + 1] = min(m[i + 1], m[i]);
    m[i] -= m[i + 1];
  }

  int r = 0;
  for (int i = n - 1; i >= 0; i--) {
    r += (i + 1) * min(k, m[i]);
    k -= min(k, m[i]);
  }
  cout << r << endl;
}
