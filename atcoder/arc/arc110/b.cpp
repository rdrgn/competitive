#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  constexpr ll N = 1e10;
  const string S = "110";
  int n;
  string s;
  cin >> n >> s;

  if (s == "1") {
    cout << 2 * N << endl;
    return 0;
  }

  int l = -1;
  for (int i = 0; i < S.size(); i++) {
    bool b = true;
    for (int j = 0; b && j < n; j++) b = b && s[j] == S[(i + j) % S.size()];
    if (b) {
      l = (n + i - 1) / S.size() + 1;
    }
  }
  cout << (l == -1 ? 0 : N - l + 1) << endl;
}
