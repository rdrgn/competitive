#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  string s;
  cin >> n >> x >> s;
  for (auto e : s) {
    if (e == 'o') {
      x++;
    } else {
      x--;
      x = max(0, x);
    }
  }
  cout << x << endl;
}
