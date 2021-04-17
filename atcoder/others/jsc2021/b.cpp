#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, int> c;
  for (int i = 0; i < n + m; i++) {
    int e;
    cin >> e;
    c[e]++;
  }

  for (auto e : c) {
    if (e.second == 1) cout << e.first << ' ';
  }
  cout << endl;
}
