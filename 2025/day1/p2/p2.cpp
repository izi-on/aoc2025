#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  int at = 50;
  int count = 0;
  while (getline(cin, input)) {
    char dir = input[0];
    int amount = stoi(input.substr(1));
    count += amount / 100;
    amount = amount % 100;
    if (dir == 'L') {
      amount *= -1;
    }
    int prev_at = at;
    at += amount;
    if ((at <= 0 or at > 99) and prev_at != 0) {
      count += 1;
    }
    at = (at < 0) ? at % 100 + 100 : at % 100;
  }
  cout << count;
  return 0;
}
