#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int r = 4;
  if (a + b >= 15 && b >= 8) {
    r = 1;
  } else if (a + b >= 10 && b >= 3) {
    r = 2;
  } else if (a + b >= 3) {
    r = 3;
  }
  cout << r << endl;
}
