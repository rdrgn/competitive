#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;

  cout << max(0, *min_element(b.begin(), b.end()) - *max_element(a.begin(), a.end()) + 1) << endl;
}
