#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-6)
#define EQ(a, b) (std::abs((a) - (b)) < EPS)
using Vector2 = std::complex<double>;
double Dot(Vector2 a, Vector2 b) { return std::real(std::conj(a) * b); }
double Cross(Vector2 a, Vector2 b) { return std::imag(std::conj(a) * b); }
double Angle(Vector2 a, Vector2 b) { return std::atan2(Cross(a, b), Dot(a, b)); }

bool compare(Vector2 a, Vector2 b) { return a.real() == b.real() ? a.imag() < b.imag() : a.real() < b.real(); }

int main() {
  int n;
  cin >> n;
  vector<Vector2> a, b;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    a.emplace_back(x, y);
  }
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    b.emplace_back(x, y);
  }

  if (n == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  vector<Vector2> ap;
  for (int i = 1; i < n; i++) {
    ap.emplace_back(Angle(a[1] - a[0], a[i] - a[0]), abs(a[i] - a[0]));
  }
  sort(ap.begin(), ap.end(), compare);

  // for (auto e : ap) cerr << e.real() << ',' << e.imag() << ' ';
  // cerr << endl;

  bool r = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;

      vector<Vector2> bp;
      for (int k = 0; k < n; k++) {
        if (k == i) continue;
        bp.emplace_back(Angle(b[j] - b[i], b[k] - b[i]), abs(b[k] - b[i]));
      }
      sort(bp.begin(), bp.end(), compare);

      // for (auto e : bp) cerr << e.real() << ',' << e.imag() << ' ';
      // cerr << endl;

      bool rij = true;
      for (int k = 0; k < n - 1; k++) {
        rij = rij && EQ(ap[k], bp[k]);
      }
      r = r || rij;
    }
  }

  cout << (r ? "Yes" : "No") << endl;
}
