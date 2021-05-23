#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& e : s) cin >> e;

  mint r = 1;
  for (int k = 0; k < h + w - 1; k++) {
    map<char, int> m;
    for (int i = max(0, k - w + 1); i < h && i <= k; i++) m[s[i][k - i]]++;
    if (m['R'] == 0 && m['B'] == 0) {
      r *= 2;
    } else if (m['R'] != 0 && m['B'] != 0) {
      r = 0;
    }
  }
  cout << r.val() << endl;
}
