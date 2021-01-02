#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<string> s, t;
  while (n--) {
    string e;
    cin >> e;
    (e.front() == '!' ? t : s).insert(e);
  }

  string r;
  for (const auto& e : s) {
    if (t.count("!" + e)) {
      r = e;
      break;
    }
  }
  cout << (r.size() ? r : "satisfiable") << endl;
}
