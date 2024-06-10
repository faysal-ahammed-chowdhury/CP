#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int hrs = atoi(s.substr(0, 2).c_str());
  int mnts = atoi(s.substr(3, 2).c_str());
  int new_hrs = hrs > 12 ? hrs - 12 : hrs;
  if (hrs == 0) {
    new_hrs = 12;
  }

  bool am = true;
  if (hrs >= 12) {
    am = false;
  }

  if (new_hrs < 10) {
    cout << 0;
  }
  cout << new_hrs << ':';
  if (mnts < 10) {
    cout << 0;
  }
  cout << mnts << ' ' << (am ? "AM\n" : "PM\n");
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}