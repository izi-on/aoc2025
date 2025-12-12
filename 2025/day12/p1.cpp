#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string input;
  vector<int> count_squares;
  for (int i = 0; i < 6; i++) {
    getline(cin, input, '\n'); // ignore first line of the block
    int count = 0;
    while (getline(cin, input, '\n')) {
      if (input == "")
        break;
      count +=
          count_if(input.begin(), input.end(), [](char n) { return n == '#'; });
      cout << input << '\n';
      cout << count << '\n';
    }
    count_squares.push_back(count);
  }

  for (auto cs : count_squares) {
    cout << cs << ' ';
  }
  cout << '\n';

  int count_feasible = 0;

  while (getline(cin, input, '\n')) {
    stringstream sstream(input);
    string elem;
    getline(sstream, elem, ' ');
    int dim_x = stoi(elem.substr(0, elem.find('x')));
    int dim_y = stoi(elem.substr(elem.find('x') + 1, elem.size() - 1));
    vector<int> shape_amt;
    while (getline(sstream, elem, ' ')) {
      shape_amt.push_back(stoi(elem));
    }

    int got = dim_x * dim_y;
    for (int i = 0; i < shape_amt.size(); i++) {
      got -= count_squares[i] * shape_amt[i];
    }
    if (got >= 0)
      count_feasible++;
  }

  cout << count_feasible << '\n';
}
