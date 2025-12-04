#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> matrix;
  string input;
  while (getline(cin, input, '\n')) {
    matrix.push_back(input);
  }

  vector<vector<int>> deltas = {{-1, 0},  {1, 0}, {0, -1}, {0, 1},
                                {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

  int n = matrix.size();
  int m = matrix[0].size();

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] != '@') {
        continue;
      }
      int count_r = 0;
      for (auto delta : deltas) {
        int it = i + delta[0];
        int jt = j + delta[1];
        if (0 <= it && it < n && 0 <= jt && jt < m) {
          count_r += (int)matrix[it][jt] == '@';
        }
      }
      if (count_r < 4)
        ans++;
    }
  }
  cout << ans;
  return 0;
}
