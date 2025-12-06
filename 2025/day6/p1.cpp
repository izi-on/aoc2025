#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

using namespace std;

bool isNotEmpty(string input) { return input != ""; };

function<long(long, long)> get_op(string op) {
  if (op == "+") {
    return plus<long>();
  } else {
    return multiplies<long>();
  }
}

int main() {
  string line;
  vector<vector<string>> matrix_elems;
  while (getline(cin, line, '\n')) {
    string raw;
    vector<string> row;
    vector<string> filteredRow;
    istringstream stream(line);
    while (getline(stream, raw, ' ')) {
      row.push_back(raw);
    }
    copy_if(row.begin(), row.end(), back_inserter(filteredRow), isNotEmpty);
    matrix_elems.push_back(filteredRow);
  }
  int n = matrix_elems.size();
  int m = matrix_elems[0].size();
  long answer = 0;
  for (int j = 0; j < m; j++) {
    vector<long> nums;
    for (int i = 0; i < n - 1; i++) {
      nums.push_back(stol(matrix_elems[i][j]));
    }
    answer += accumulate(nums.begin(), nums.end(),
                         (matrix_elems[n - 1][j] == "+") ? 0L : 1L,
                         get_op(matrix_elems[n - 1][j]));
  }
  cout << answer;
  return 0;
}
