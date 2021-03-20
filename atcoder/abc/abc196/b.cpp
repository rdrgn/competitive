#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string r;
  for (auto e : s) {
    if (e == '.') break;
    r.push_back(e);
  }
  cout << r << endl;
}
