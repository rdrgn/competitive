#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<array<int, 2>> r(n);
  for (int i = 0, b = 1 << 1; i < n; i++) {
    r[i] = {(2 * i) % n, (2 * i + 1) % n};
    b <<= 1;
    if (b > n) b = 1 << 1;
  }

  for (auto e : r) cout << e[0] + 1 << ' ' << e[1] + 1 << endl;

  // int m = 0;
  // for (int i = 0; i < n; i++) {
  //   vector<int> d(n, 1e9);
  //   d[i] = 0;
  //   queue<int> q;
  //   q.push(i);
  //   while (!q.empty()) {
  //     auto e = q.front();
  //     q.pop();
  //     for (auto e2 : r[e]) {
  //       if (d[e] + 1 >= d[e2]) continue;
  //       d[e2] = d[e] + 1;
  //       q.push(e2);
  //     }
  //   }
  //   m = max(m, *max_element(d.begin(), d.end()));
  // }
  // cerr << "max: " << m << endl;
}
