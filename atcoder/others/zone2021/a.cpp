#include <bits/stdc++.h>
using namespace std;

int main() {
  string S = "ZONe";
  string s;
  cin >> s;
  int r = 0;
  for (int i = 0; i + 4 <= s.size(); i++) {
    if (s.substr(i, 4) == S) r++;
  }
  cout << r << endl;
}
