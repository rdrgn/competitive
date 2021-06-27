#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int r = -1;
  if (s.front() != s.back()) {
    r = 1;
  } else if (n > 3) {
    for (int i = 1; i + 1 < n - 1 && r == -1; i++) {
      if (s[0] != s[i] && s[i + 1] != s.back()) r = 2;
    }
  }
  cout << r << endl;
}
