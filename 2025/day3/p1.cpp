#include <iostream>
#include <string>
#include <vector>
using namespace std;

int get_max(const string &pbank, int s, int e) {
  int max = -1;
  int max_i = -1;
  for (int i = e - 1; i >= s; i--) {
    int cur = pbank[i] - '0';
    if (cur >= max) {
      max = cur;
      max_i = i;
    }
  }
  return max_i;
}

int main() {
  string input;
  vector<string> pbanks;
  while (getline(cin, input, '\n')) {
    pbanks.push_back(input);
  }
  int ans = 0;
  for (auto pbank : pbanks) {
    int fs = get_max(pbank, 0, pbank.size() - 1);
    int snd = get_max(pbank, fs + 1, pbank.size());
    ans += (pbank[fs] - '0') * 10 + (pbank[snd] - '0');
  }
  cout << ans;
  return 0;
}
