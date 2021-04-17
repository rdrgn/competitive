#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int n, p;
  cin >> n >> p;
  cout << (mint(p - 1) * mint(p - 2).pow(n - 1)).val() << endl;
}
