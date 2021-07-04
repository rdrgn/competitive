#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;

  vector<int> f(11);
  f[0] = 1;
  for (int i = 1; i < f.size(); i++) f[i] = f[i - 1] * i;

  int r = 0;
  for (auto it = f.rbegin(); it != f.rend() && p; it++) {
    r += p / *it;
    p %= *it;
  }
  cout << r << endl;
}
