#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int r = 1;
  for (int i = 2; i <= b; i++) {
    if (a <= (b / i - 1) * i) r = i;
  }
  cout << r << endl;
}
