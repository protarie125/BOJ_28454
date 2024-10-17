#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

using YMD = tuple<ll, ll, ll>;
YMD StrToTuple(const string& ymd_str) {
  // ymd_str = "YYYY-MM-DD"
  auto iss = istringstream{ymd_str.substr(0, 4)};
  ll y;
  iss >> y;

  iss = istringstream{ymd_str.substr(5, 2)};
  ll m;
  iss >> m;

  iss = istringstream{ymd_str.substr(8, 2)};
  ll d;
  iss >> d;

  return {y, m, d};
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string now;
  cin >> now;
  const auto& [ny, nm, nd] = StrToTuple(now);

  ll n;
  cin >> n;

  ll ans = 0;
  while (0 < (n--)) {
    string s;
    cin >> s;
    const auto& [y, m, d] = StrToTuple(s);

    if (y > ny) {
      ++ans;
    } else if (y == ny) {
      if (m > nm) {
        ++ans;
      } else if (m == nm) {
        if (d >= nd) {
          ++ans;
        }
      }
    }
  }

  cout << ans;

  return 0;
}