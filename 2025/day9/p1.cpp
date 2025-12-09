#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  vector<pair<int, int>> coords;
  while (getline(cin, input, '\n')) {
    cout << input << '\n';
    coords.push_back({stoi(input.substr(0, input.find(','))),
                      stoi(input.substr(input.find(',') + 1))});
  }
  long ans = 0;
  for (int i = 0; i < coords.size(); i++) {
    for (int j = i + 1; j < coords.size(); j++) {
      pair<int, int> p1 = coords[i];
      pair<int, int> p2 = coords[j];
      bool count = true;
      for (int k = 0; k < coords.size(); k++) {
        pair<int, int> line_s = coords[k];
        pair<int, int> line_e = coords[(k + 1) % coords.size()];

        int tl_x = min(p1.first, p2.first);
        int tl_y = min(p1.second, p2.second);
        int br_x = max(p1.first, p2.first);
        int br_y = max(p1.second, p2.second);

        int ls_x = min(line_s.first, line_e.first);
        int ls_y = min(line_s.second, line_e.second);

        int le_x = max(line_s.first, line_e.first);
        int le_y = max(line_s.second, line_e.second);

        if (!((le_x <= tl_x || br_x <= ls_x) ||
              (le_y <= tl_y || br_y <= ls_y))) {
          count = false;
          break;
        }
      }
      if (count) {
        long dx = abs(coords[i].first - coords[j].first) + 1;
        long dy = abs(coords[i].second - coords[j].second) + 1;
        ans = max(ans, dx * dy);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
