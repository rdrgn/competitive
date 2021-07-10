#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  sort(a.begin(), a.end());

  mint r = 1;
  for (int i = 0; i < n; i++) {
    r *= max(0, a[i] - i);
  }
  cout << r.val() << endl;
}
