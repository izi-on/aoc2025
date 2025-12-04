
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
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

  map<tuple<int, int>, set<tuple<int, int>>> adj_list;
  deque<tuple<int, int>> deque;
  set<tuple<int, int>> queued;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] != '@') {
        continue;
      }
      tuple<int, int> cur_r(i, j);
      for (auto delta : deltas) {
        int it = i + delta[0];
        int jt = j + delta[1];
        if (0 <= it && it < n && 0 <= jt && jt < m && matrix[it][jt] == '@') {
          tuple<int, int> adj(it, jt);
          adj_list[cur_r].insert(adj);
        }
      }
      if (adj_list[cur_r].size() < 4) {
        deque.push_back(cur_r);
        queued.insert(cur_r);
      }
    }
  }

  while (!deque.empty()) {
    auto cur_r = deque.front();
    deque.pop_front();
    ans++;
    for (auto adj : adj_list[cur_r]) {
      adj_list[adj].erase(cur_r);
      if (adj_list[adj].size() < 4 && queued.count(adj) == 0) {
        deque.push_back(adj);
        queued.insert(adj);
      }
    }
  }

  cout << ans;
  return 0;
}
