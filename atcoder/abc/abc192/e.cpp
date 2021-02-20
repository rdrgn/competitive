#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

template <class T>
vector<T> Dijkstra(const vector<vector<pair<int, pair<T, T>>>>& graph, int s) {
  vector<T> dist(graph.size(), INF);
  priority_queue<pair<T, int>> q;
  q.push(pair<T, int>{0, s});
  while (!q.empty()) {
    int i = q.top().second;
    T di = -q.top().first;
    q.pop();
    if (dist[i] <= di) continue;
    dist[i] = di;
    for (auto e : graph[i]) {
      int j = e.first;
      T dj = di + (e.second.second - di % e.second.second) % e.second.second + e.second.first;
      if (dist[j] > dj) q.push(pair<T, int>{-dj, j});
    }
  }
  return dist;
}

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--, y--;
  vector<vector<pair<int, pair<ll, ll>>>> g(n);
  while (m--) {
    ll a, b, t, k;
    cin >> a >> b >> t >> k;
    a--, b--;
    g[a].push_back({b, {t, k}});
    g[b].push_back({a, {t, k}});
  }

  auto d = Dijkstra(g, x);
  cout << (d[y] == INF ? -1 : d[y]) << endl;
}
