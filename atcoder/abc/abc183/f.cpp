#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

struct Query {
  int i, y;
};

struct Node {
  Node *a = nullptr, *b = nullptr;
  int c;
  vector<Query> q;
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> c(n);
  for (auto& e : c) {
    cin >> e;
    e--;
  }

  vector<Node*> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i] = new Node;
    nodes[i]->c = c[i];
  }

  dsu d(n);
  int q2 = 0;
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    if (t == 1) {
      if (!d.same(a, b)) {
        auto node = new Node;
        node->a = nodes[d.leader(a)];
        node->b = nodes[d.leader(b)];
        d.merge(a, b);
        nodes[d.leader(a)] = node;
      }
    } else if (t == 2) {
      nodes[d.leader(a)]->q.push_back(Query{q2, b});
      q2++;
    }
  }

  vector<int> s(n), r(q2);
  auto dfs = [&](auto&& dfs, Node* node) -> void {
    for (auto e : node->q) r[e.i] -= s[e.y];
    if (node->a == nullptr) {
      s[node->c]++;
    } else {
      dfs(dfs, node->a);
      dfs(dfs, node->b);
    }
    for (auto e : node->q) r[e.i] += s[e.y];
  };
  for (const auto& group : d.groups()) dfs(dfs, nodes[d.leader(group.front())]);

  for (auto e : r) cout << e << endl;
}
