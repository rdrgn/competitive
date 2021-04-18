#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  vector<int> r;
  r.reserve(a + b);
  for (int i = -b; i <= -1; i++) r.push_back(i);
  for (int i = 1; i <= a; i++) r.push_back(i);

  int s = 0;
  for (auto e : r) s += e;
  (s < 0 ? r.back() : r.front()) -= s;

  for (auto e : r) cout << e << ' ';
  cout << endl;
}
