#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <atcoder/all>
using namespace atcoder;

ll inversion_number(const vector<ll>& a) {
  fenwick_tree<ll> fw(a.size());
  ll r = 0;
  for (int i = 0; i < a.size(); i++) {
    r += i - fw.sum(0, a[i] + 1);
    fw.add(a[i], 1);
  }
  return r;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;

  for (int i = 0; i < n; i++) {
    a[i] += i;
    b[i] += i;
  }

  auto sa = a, sb = b;
  sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());
  bool possible = true;
  for (int i = 0; i < n; i++) possible = possible && sa[i] == sb[i];
  if (!possible) {
    cout << -1 << endl;
    return 0;
  }

  map<ll, queue<int>> mq;
  for (int i = 0; i < n; i++) mq[b[i]].push(i);

  auto v = a;
  for (auto& e : v) {
    auto t = mq[e].front();
    mq[e].pop();
    e = t;
  }

  cout << inversion_number(v) << endl;
}
