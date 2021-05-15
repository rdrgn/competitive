#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, string>> a(n);
  for (auto& e : a) cin >> e.second >> e.first;
  sort(a.rbegin(), a.rend());
  cout << a[1].second << endl;
}
