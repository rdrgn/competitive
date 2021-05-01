#include <bits/stdc++.h>
using namespace std;

template <class T>
std::vector<T> Dijkstra(const std::vector<std::vector<std::pair<int, T>>>& graph, int s) {
  std::vector<T> dist(graph.size(), std::numeric_limits<T>::max());
  std::priority_queue<std::pair<T, int>> q;
  q.emplace(0, s);
  while (!q.empty()) {
    int i = q.top().second;
    T di = -q.top().first;
    q.pop();
    if (dist[i] < di) continue;
    for (auto e : graph[i]) {
      int j = e.first;
      T dj = di + e.second;
      if (dist[j] <= dj) continue;
      dist[j] = dj;
      q.emplace(-dj, j);
    }
  }
  return dist;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w - 1)), b(h - 1, vector<int>(w));
  for (auto& e : a) {
    for (auto& e : e) cin >> e;
  }
  for (auto& e : b) {
    for (auto& e : e) cin >> e;
  }

  vector<vector<pair<int, int>>> g(2 * h * w);
  auto add_edge = [&g](int a, int b, int cost) { g[a].push_back({b, cost}); };
  auto ni = [h, w](int i, int j, int k) { return i * w + j + k * h * w; };

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j + 1 < w) {
        add_edge(ni(i, j, 0), ni(i, j + 1, 0), a[i][j]);
        add_edge(ni(i, j, 1), ni(i, j + 1, 0), a[i][j]);
      }
      if (j - 1 >= 0) {
        add_edge(ni(i, j, 0), ni(i, j - 1, 0), a[i][j - 1]);
        add_edge(ni(i, j, 1), ni(i, j - 1, 0), a[i][j - 1]);
      }
      if (i + 1 < h) {
        add_edge(ni(i, j, 0), ni(i + 1, j, 0), b[i][j]);
        add_edge(ni(i, j, 1), ni(i + 1, j, 0), b[i][j]);
      }
      if (i - 1 >= 0) {
        add_edge(ni(i, j, 0), ni(i - 1, j, 1), 2);
        add_edge(ni(i, j, 1), ni(i - 1, j, 1), 1);
      }
    }
  }

  auto r = Dijkstra(g, ni(0, 0, 0));
  cout << r[ni(h - 1, w - 1, 0)] << endl;
}
