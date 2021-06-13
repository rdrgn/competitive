#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    s.insert(e);
  }
  cout << (s.size() == n && *s.begin() == 1 && *s.rbegin() == n ? "Yes" : "No") << endl;
}
