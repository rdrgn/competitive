#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t >> a[i].first >> a[i].second;
    t--;
    a[i].first *= 2;
    a[i].second *= 2;
    if (t / 2) a[i].first++;
    if (t % 2) a[i].second--;
  }
  sort(a.begin(), a.end());

  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j].first <= a[i].second) r++;
    }
  }
  cout << r << endl;
}
