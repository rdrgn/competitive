#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  set<pair<int, int>> s;
  s.insert({0, 0});
  for (auto e : a) {
    set<pair<int, int>> s2;
    for (auto p : s) {
      s2.insert({p.first + e, p.second});
      s2.insert({p.first, p.second + e});
    }
    s = s2;
  }

  int r = 1e9;
  for (auto p : s) r = min(r, max(p.first, p.second));
  cout << r << endl;
}
