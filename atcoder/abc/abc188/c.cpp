#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  n = 1 << n;
  vector<int> a(n);
  for (auto& e : a) cin >> e;

  int i = max_element(a.begin(), a.begin() + n / 2) - a.begin();
  int j = max_element(a.begin() + n / 2, a.end()) - a.begin();
  cout << (a[i] < a[j] ? i : j) + 1 << endl;
}
