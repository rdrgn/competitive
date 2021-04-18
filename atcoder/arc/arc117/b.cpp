#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main() {
  int n;
  cin >> n;

  set<int> s;
  s.insert(0);
  while (n--) {
    int e;
    cin >> e;
    s.insert(e);
  }
  vector<int> v(s.begin(), s.end());

  mint r = 1;
  for (int i = 1; i < v.size(); i++) r *= v[i] - v[i - 1] + 1;
  cout << r.val() << endl;
}
