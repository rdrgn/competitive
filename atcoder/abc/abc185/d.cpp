#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &e : a) cin >> e;

  a.push_back(0);
  a.push_back(n + 1);
  sort(a.begin(), a.end());

  vector<int> d;
  for (int i = 0; i < m + 1; i++) {
    int e = a[i + 1] - a[i] - 1;
    if (e) d.push_back(e);
  }

  int k = *min_element(d.begin(), d.end());

  int r = 0;
  for (auto e : d) r += (e - 1) / k + 1;

  cout << r << endl;
}
