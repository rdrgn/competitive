#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  ll r = 0;
  vector<int> c(CHAR_MAX);
  for (int i = n - 1; i >= 0; i--) {
    c[s[i]]++;
    if (i + 2 < n && s[i] == s[i + 1] && s[i] != s[i + 2]) {
      r += n - i - c[s[i]];
      fill(c.begin(), c.end(), 0);
      c[s[i]] = n - i;
    }
  }
  cout << r << endl;
}
