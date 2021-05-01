#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  bool reversed = false;
  string l, r;
  for (auto e : s) {
    if (e == 'R') {
      reversed ^= true;
    } else {
      (reversed ? l : r).push_back(e);
    }
  }
  string t;
  if (reversed) {
    reverse(r.begin(), r.end());
    t = r + l;
  } else {
    reverse(l.begin(), l.end());
    t = l + r;
  }

  string u;
  for (auto e : t) {
    if (!u.empty() && u.back() == e) {
      u.pop_back();
    } else {
      u.push_back(e);
    }
  }

  cout << u << endl;
}
