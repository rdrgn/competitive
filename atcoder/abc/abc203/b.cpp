#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int r = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) r += i * 100 + j;
  }
  cout << r << endl;
}
