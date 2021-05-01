#include <bits/stdc++.h>
using namespace std;
constexpr int W = 50;
constexpr int H = 50;

const string D = "UDLR";
const int DI[] = {-1, 1, 0, 0};
const int DJ[] = {0, 0, -1, 0};

class Timer {
 public:
  Timer() : time_begin(Now()) {}
  int Elapsed() { return std::chrono::duration_cast<std::chrono::milliseconds>(Now() - time_begin).count(); }

 private:
  std::chrono::system_clock::time_point time_begin;
  static std::chrono::system_clock::time_point Now() { return std::chrono::system_clock::now(); }
};

int main() {
  Timer timer;

  int si, sj;
  cin >> si >> sj;
  vector T(H, vector<int>(W)), P(H, vector<int>(W));
  for (auto& e : T) {
    for (auto& e : e) cin >> e;
  }
  for (auto& e : P) {
    for (auto& e : e) cin >> e;
  }

  int rp = 0;
  vector<int> rv;

  {
    int p = 0, i = si, j = sj;
    vector<int> v;
    v.reserve(H * W);
    bitset<H * W> s;
    s[T[i][j]] = true;
    auto f = [&](auto&& f) -> void {
      if (timer.Elapsed() > 1900) return;

      int i1 = i, j1 = j;
      for (int d = 0; d < 4; d++) {
        int i2 = i1 + DI[d], j2 = j1 + DJ[d];
        if (i2 < 0 || H <= i2) continue;
        if (j2 < 0 || W <= j2) continue;
        if (s[T[i2][j2]]) continue;

        i = i2;
        j = j2;
        p += P[i2][j2];
        v.push_back(d);
        s[T[i2][j2]] = true;

        f(f);

        p -= P[i2][j2];
        v.pop_back();
        s[T[i2][j2]] = false;
      }

      if (p > rp) {
        rp = p;
        rv = v;
      }
    };
    f(f);
  }

  cerr << "score: " << rp << endl;
  for (auto e : rv) cout << D[e];
  cout << endl;
}
