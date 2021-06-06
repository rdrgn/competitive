#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r = 0;
  while (n--) {
    int e;
    cin >> e;
    r += max(0, e - 10);
  }
  cout << r << endl;
}
