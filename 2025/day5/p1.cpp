#include <iostream>
using namespace std;

int main() {
  string input;
  vector<pair<long, long>> ranges;
  vector<long> ids;
  while (getline(cin, input, '\n')) {
    if (input == "")
      break;
    pair<long, long> range(stol(input.substr(0, input.find('-'))),
                           stol(input.substr(input.find('-') + 1)));
    ranges.push_back(range);
  }
  while (getline(cin, input, '\n')) {
    ids.push_back(stol(input));
  }

  sort(ranges.begin(), ranges.end());
  vector<pair<long, long>> no_ranges;
  long prev_start = ranges[0].first;
  long max_end = ranges[0].second;
  for (int i = 1; i < ranges.size(); i++) {
    long cs = ranges[i].first;
    long ce = ranges[i].second;
    if (max_end < cs) {
      pair<long, long> np(prev_start, max_end);
      no_ranges.push_back(np);
      prev_start = cs;
    }
    max_end = max(max_end, ce);
  }
  pair<long, long> np(prev_start, max_end);
  no_ranges.push_back(np);

  int count = 0;
  for (auto id : ids) {
    int l = 0;
    int r = no_ranges.size() - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (no_ranges[mid].first <= id) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (ans != -1 && id <= no_ranges[ans].second) {
      count++;
    }
  }
  cout << count;
  return 0;
}
