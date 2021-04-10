#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n + 1);
  for (auto& e : a) cin >> e;

  for (int k = *max_element(a.begin(), a.end()); k >= 1; k--) {
    bool valid = true;
    for (int i = 0; valid && i < n; i++) {
      int l1 = a[i] / k, l2, l3;
      int r1 = a[i + 1] / k, r2, r3;
      l2 = l3 = l1;
      r2 = r3 = r1;
      if (a[i] % k > a[i + 1] % k) l2++;
      if (a[i] % k < a[i + 1] % k) r2++;
      if (a[i] % k != 0) l3++;
      if (a[i + 1] % k != 0) r3++;

      if (s[i] == '<') {
        valid = valid && l1 < r1 && l2 < r2 && l3 < r3;
      } else {
        valid = valid && l1 > r1 && l2 > r2 && l3 > r3;
      }
    }
    if (!valid) continue;

    cout << k << endl;
    for (int j = 0; j < k; j++) {
      for (int i = 0; i < n + 1; i++) cout << a[i] / k + (j < a[i] % k ? 1 : 0) << ' ';
      cout << endl;
    }
    return 0;
  }

  return 1;
}
