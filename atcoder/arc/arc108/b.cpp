#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  const string S = "fox";
  string r;
  for (auto e : s) {
    r.push_back(e);
    if (r.size() >= S.size() && r.substr(r.size() - 3) == S) {
      for (auto _ : S) r.pop_back();
    }
  }
  cout << r.size() << endl;
}
