#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll _InversionNumber(vector<int>& a) {
  int n = a.size();
  if (n <= 1) return 0;

  ll r = 0;
  vector<int> b(a.begin(), a.begin() + n / 2), c(a.begin() + n / 2, a.end());

  r += _InversionNumber(b);
  r += _InversionNumber(c);

  int ai = 0, bi = 0, ci = 0;
  while (ai < n) {
    if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
      a[ai++] = b[bi++];
    } else {
      r += n / 2 - bi;
      a[ai++] = c[ci++];
    }
  }
  return r;
}

ll InversionNumber(vector<int> a) { return _InversionNumber(a); }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  ll r = InversionNumber(a);
  for (int i = 0; i < n; i++) {
    cout << r << endl;
    r -= a[i];
    r += n - 1 - a[i];
  }
}
