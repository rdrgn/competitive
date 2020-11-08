#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n, m;
  cin >> h >> w >> n >> m;

  vector v(h, string(w, '.'));
  while (n--) {
    int i, j;
    cin >> i >> j;
    v[i - 1][j - 1] = 'o';
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    v[i - 1][j - 1] = '#';
  }

  vector s(h, vector(w, vector<int>(4)));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v[i][j] == 'o') s[i][j][0] = s[i][j][1] = s[i][j][2] = s[i][j][3] = true;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if (v[i][j] != '#') s[i][j][0] |= s[i][j - 1][0];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = w - 2; j >= 0; j--) {
      if (v[i][j] != '#') s[i][j][1] |= s[i][j + 1][1];
    }
  }
  for (int i = 1; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v[i][j] != '#') s[i][j][2] |= s[i - 1][j][2];
    }
  }
  for (int i = h - 2; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      if (v[i][j] != '#') s[i][j][3] |= s[i + 1][j][3];
    }
  }

  int r = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j][0] || s[i][j][1] || s[i][j][2] || s[i][j][3]) r++;
    }
  }
  cout << r << endl;
}
