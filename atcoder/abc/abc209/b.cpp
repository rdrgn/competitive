#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int s = 0;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    if (i % 2) e--;
    s += e;
  }
  cout << (s <= x ? "Yes" : "No") << endl;
}
