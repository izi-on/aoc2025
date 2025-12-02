#include <iostream>
#include <string>
using namespace std;

int main() {
  int at = 50;
  int count = 0;
  string input;
  while (getline(cin, input)) {
    string dir;
    int amount;
    dir = input[0];
    amount = stoi(input.substr(1));
    if (dir == "L") {
      amount *= -1;
    }
    at = (at + amount) % 100;
    if (at == 0) {
      count++;
    }
  }
  cout << count;
  return 0;
}
