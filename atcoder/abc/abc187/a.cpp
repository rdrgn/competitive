#include <bits/stdc++.h>
using namespace std;

int s(const string& a) {
  return accumulate(a.begin(), a.end(), 0, [](int acc, int i) { return acc + (i - '0'); });
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << max(s(a), s(b)) << endl;
}
