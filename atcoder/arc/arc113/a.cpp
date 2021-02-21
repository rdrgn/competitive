#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int k;
  cin >> k;
  ll r = 0;
  for (int a = 1; a <= k; a++) {
    for (int b = 1; a * b <= k; b++) {
      r += k / (a * b);
    }
  }
  cout << r << endl;
}
