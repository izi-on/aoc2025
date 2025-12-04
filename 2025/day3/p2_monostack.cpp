
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> pbanks;
  string input;
  while (getline(cin, input, '\n')) {
    pbanks.push_back(input);
  }
  long ans = 0;
  for (auto pbank : pbanks) {
    vector<char> monostack;
    for (int i = 0; i < pbank.size(); i++) {
      char d = pbank[i];
      while (!monostack.empty() && monostack.back() < d &&
             monostack.size() + pbank.size() - i - 1 >= 12) {
        monostack.pop_back();
      }
      monostack.push_back(d);
    }
    string str(monostack.begin(), monostack.begin() + 12);
    ans += stol(str);
    cout << str << "\n";
  }
  cout << ans << "\n";
  return 0;
}
