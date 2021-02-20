#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool r = true;
  for (int i = 0; i < s.size(); i++) {
    r = r && (i % 2 ? 'A' <= s[i] && s[i] <= 'Z' : 'a' <= s[i] && s[i] <= 'z');
  }
  cout << (r ? "Yes" : "No") << endl;
}
