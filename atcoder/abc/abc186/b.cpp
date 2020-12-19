#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<int> a(h * w);
  for (auto& e : a) cin >> e;

  cout << accumulate(a.begin(), a.end(), 0) - h * w * *min_element(a.begin(), a.end()) << endl;
}
