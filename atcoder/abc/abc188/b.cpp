#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;

  int p = 0;
  for (int i = 0; i < n; i++) p += a[i] * b[i];
  cout << (p == 0 ? "Yes" : "No") << endl;
}
