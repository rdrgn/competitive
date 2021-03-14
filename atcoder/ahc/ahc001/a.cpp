#include <bits/stdc++.h>
using namespace std;
constexpr int W = 10000;
constexpr int H = 10000;

enum class Direction : int { Left, Top, Right, Bottom };

class Rectangle {
 public:
  int x1, y1, x2, y2;
  int Area() const { return (x2 - x1) * (y2 - y1); }
};

class Request {
 public:
  int x, y, r;
  double Score(const Rectangle& rectangle) const {
    if (rectangle.x1 < 0 || W <= rectangle.x2 || rectangle.y1 < 0 || W <= rectangle.y2) return 0;
    if (x < rectangle.x1 || rectangle.x2 <= x || y < rectangle.y1 || rectangle.y2 <= y) return 0;
    pair<double, double> p = minmax((double)r, (double)rectangle.Area());
    return 1.0 - pow(1.0 - p.first / p.second, 2.0);
  }
};

using I = vector<Request>;
using O = vector<Rectangle>;

void Infrate(I& input, O& output, int index, int directions_rotation) {
  vector<Direction> directions{Direction::Left, Direction::Top, Direction::Right, Direction::Bottom};
  rotate(directions.begin(), directions.begin() + directions_rotation % 4, directions.end());

  vector<double> scores(4);

  auto prev_score = input[index].Score(output[index]);

  vector<Rectangle> next_rectangles(4, output[index]);

  if (output[index].Area() < input[index].r) {
    for (int i = 0; i < directions.size(); i++) {
      switch (directions[i]) {
        case Direction::Left:
          next_rectangles[i].x1--;
          break;
        case Direction::Top:
          next_rectangles[i].y1--;
          break;
        case Direction::Right:
          next_rectangles[i].x2++;
          break;
        case Direction::Bottom:
          next_rectangles[i].y2++;
          break;
      }
    }
  } else if (output[index].Area() > input[index].r) {
    for (int i = 0; i < directions.size(); i++) {
      switch (directions[i]) {
        case Direction::Left:
          next_rectangles[i].x1++;
          break;
        case Direction::Top:
          next_rectangles[i].y1++;
          break;
        case Direction::Right:
          next_rectangles[i].x2--;
          break;
        case Direction::Bottom:
          next_rectangles[i].y2--;
          break;
      }
    }
  }
  for (int i = 0; i < directions.size(); i++) {
    auto s = input[index].Score(next_rectangles[i]);
    if (s == 0) {
      scores[i] = -1;
    } else {
      scores[i] += s - prev_score;
    }
  }

  vector<vector<pair<int, Rectangle>>> next_other_rectangles(4);

  if (output[index].Area() < input[index].r) {
    for (int i = 0; i < directions.size(); i++) {
      if (scores[i] == -1) continue;
      bool did_push = false;
      for (int j = 0; j < input.size(); j++) {
        auto r = output[j];
        bool is_pushed = false;
        switch (directions[i]) {
          case Direction::Left:
            if (output[index].y1 < r.y2 && r.y1 < output[index].y2 && output[index].x1 == r.x2) {
              r.x2--;
              is_pushed = true;
              did_push = true;
            }
            break;
          case Direction::Top:
            if (output[index].x1 < r.x2 && r.x1 < output[index].x2 && output[index].y1 == r.y2) {
              r.y2--;
              is_pushed = true;
              did_push = true;
            }
            break;
          case Direction::Right:
            if (output[index].y1 < r.y2 && r.y1 < output[index].y2 && output[index].x2 == r.x1) {
              r.x1++;
              is_pushed = true;
              did_push = true;
            }
            break;
          case Direction::Bottom:
            if (output[index].x1 < r.x2 && r.x1 < output[index].x2 && output[index].y2 == r.y1) {
              r.y1++;
              is_pushed = true;
              did_push = true;
            }
            break;
        }
        if (is_pushed) {
          auto s1 = input[j].Score(output[j]);
          auto s2 = input[j].Score(r);
          if (s2 == 0) {
            scores[i] = -1;
            break;
          } else {
            scores[i] += s2 - s1;
            next_other_rectangles[i].push_back({j, r});
          }
        }
      }
      if (!did_push) scores[i] += 1;
    }
  }

  auto mi = max_element(scores.begin(), scores.end()) - scores.begin();
  if (scores[mi] > 0) {
    output[index] = next_rectangles[mi];
    for (const auto& e : next_other_rectangles[mi]) output[e.first] = e.second;
  }
}

int main() {
  int n;
  cin >> n;
  I input(n);
  for (auto& e : input) cin >> e.x >> e.y >> e.r;

  O output(n);
  for (int i = 0; i < n; i++) output[i] = {input[i].x, input[i].y, input[i].x + 1, input[i].y + 1};

  for (int iteration = 0; iteration < (int)1e6; iteration++) {
    Infrate(input, output, iteration % n, iteration / n);
  }

  for (auto e : output) cout << e.x1 << ' ' << e.y1 << ' ' << e.x2 << ' ' << e.y2 << endl;
}
