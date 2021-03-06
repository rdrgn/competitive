#include <bits/stdc++.h>
using namespace std;

using I = vector<int>;
using O = int;

O solve(const I& input) {
  auto a = input;

  int r = 0;
  for (int i = 0; i < a.size(); i += 2) {
    if (a[i] != 10 && a[i] + a[i + 1] == 10) r++;
  }

  return r;
}

int main() {
  vector<O> r;

  r.push_back(solve({10, 0, 9, 1, 8, 1, 7, 3, 6, 2, 5, 5, 4, 5, 2, 8, 2, 3, 1, 8}));
  r.push_back(solve({5, 5, 4, 4, 3, 7, 6, 4, 7, 3, 9, 1, 5, 2, 1, 1, 0, 0, 9, 0}));
  r.push_back(solve({0, 10, 1, 9, 10, 0, 10, 0, 2, 8, 0, 10, 1, 9, 9, 0, 1, 8, 2, 2}));

  for (int i = 0; i < r.size(); i++) cout << r[i] << "\n,"[i < r.size() - 1];
}
