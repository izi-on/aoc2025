#include <iostream>
#include <string>
#include <vector>
using namespace std;

long ipow(long base, long exp) {
  long result = 1;
  while (exp) {
    if (exp & 1) {
      result *= base;
    }
    exp >>= 1;
    base *= base;
  }
  return result;
}

int count_dig(long num) {
  int count = 0;
  while (num) {
    count++;
    num /= 10;
  }
  return count;
}

int main() {
  vector<string> pbanks;
  string input;
  while (getline(cin, input, '\n')) {
    pbanks.push_back(input);
  }
  long ans = 0;
  for (auto pbank : pbanks) {
    int cols = pbank.size() + 1;
    int rows = 13;
    vector<vector<long>> dp(rows, vector<long>(cols, 0));
    for (int i = 1; i <= 12; i++) {
      for (int j = cols - 2; j >= 0; j--) {
        long cur_max = 0;
        if (count_dig(dp[i][j + 1]) == i) {
          cur_max = dp[i][j + 1];
        }
        if (count_dig(dp[i - 1][j + 1]) == i - 1) {
          cur_max = max(cur_max,
                        (pbank[j] - '0') * ipow(10, i - 1) + dp[i - 1][j + 1]);
        }
        dp[i][j] = cur_max;
      }
    }

    // backtrack
    int ti = 12;
    int tj = 0;
    string ans_s = "";
    while (dp[ti][tj] != 0) {
      if (dp[ti][tj] > dp[ti][tj + 1]) {
        ans_s += pbank[tj];
        tj++;
        ti--;
      } else {
        tj++;
      }
    }
    ans += stol(ans_s);
  }
  cout << ans;
  return 0;
}
