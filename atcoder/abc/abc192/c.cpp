#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  while (k--) {
    auto s1 = to_string(n);
    auto s2 = s1;
    sort(s1.rbegin(), s1.rend());
    sort(s2.begin(), s2.end());
    n = stoi(s1) - stoi(s2);
  }
  cout << n << endl;
}
