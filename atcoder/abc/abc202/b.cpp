#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for (auto& e : s) {
    if (e == '6') {
      e = '9';
    } else if (e == '9') {
      e = '6';
    }
  }
  cout << s << endl;
}
