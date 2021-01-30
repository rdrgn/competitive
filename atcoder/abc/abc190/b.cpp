#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s, d;
  cin >> n >> s >> d;
  bool r = false;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if (x < s && y > d) r = true;
  }
  cout << (r ? "Yes" : "No") << endl;
}
