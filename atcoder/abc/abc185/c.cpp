#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int l;
  cin >> l;

  vector c(l + 1, vector<ll>(l + 1));
  for (int i = 0; i <= l; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }

  cout << c[l - 1][11] << endl;
}
