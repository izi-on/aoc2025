#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

long bruh(pair<long, long> range) { return range.second - range.first + 1L; }

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

  long count = 0;
  vector<long> counts(no_ranges.size());
  transform(no_ranges.begin(), no_ranges.end(), counts.begin(), bruh);
  cout << accumulate(counts.begin(), counts.end(), 0L);

  return 0;
}
