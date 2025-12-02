#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int get_dig_count(long num) {
  int dig_count = 0;
  long cnum = num;
  while (cnum) {
    dig_count += 1;
    cnum /= 10;
  }
  return dig_count;
}

long get_half(long num) {
  int dig_count = get_dig_count(num);
  long half_num = 0;
  int pos = 1;
  for (int i = 0; i < dig_count; i++) {
    int dig = num % 10;
    num /= 10;
    if (i < dig_count / 2) {
      continue;
    }
    half_num = half_num + dig * pos;
    pos *= 10;
  }
  return half_num;
}

long make_half(long num, bool is_upper) {
  int dig = get_dig_count(num);
  long half = get_half(num);
  if (dig % 2) {
    if (is_upper) {
      return pow(10, dig / 2) - 1;
    } else {
      return pow(10, dig / 2);
    }
  } else {
    return half;
  }
}

int main() {
  string input;
  vector<string> inputv;
  while (getline(cin, input, ',')) {
    inputv.push_back(input);
  }
  long ans = 0;
  for (auto inp : inputv) {
    long lower = stol(inp.substr(0, inp.find('-')));
    long upper = stol(inp.substr(inp.find('-') + 1));
    long count = 0;
    long fhalf = make_half(lower, false);
    long shalf = make_half(upper, true);
    for (int i = fhalf; i <= shalf; i++) {
      long candidate = i * pow(10, get_dig_count(i)) + i;
      if (lower <= candidate && candidate <= upper) {
        ans += candidate;
      }
    }
  }
  cout << ans;
  return ans;
}
