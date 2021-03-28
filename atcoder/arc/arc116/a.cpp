#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    if (n % 2 == 0 && n / 2 % 2 != 0) {
      cout << "Same" << endl;
    } else if (n % 2 == 0) {
      cout << "Even" << endl;
    } else {
      cout << "Odd" << endl;
    }
  }
}
