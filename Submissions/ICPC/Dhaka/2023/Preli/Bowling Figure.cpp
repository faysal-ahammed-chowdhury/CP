#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  string s; cin >> s;
  int n = (int) s.size();
  int x = n / 6;
  int y = n % 6;
  int r = 0, w = 0;
  for (auto c : s) {
    if (c == 'W') w++;
    else r += c - '0';
  }
  string s1 = "Overs";
  string s2 = "Runs";
  string s3 = "Wickets";
  if (r <= 1) {
    s2 = "Run";
  }
  if (w <= 1) {
    s3 = "Wicket";
  }
  if (x < 1) {
    s1 = "Over";
  }
  else if (x == 1) {
    if (y == 0) s1 = "Over";
  }

  cout << x << '.' << y << " " << s1 << " " << r << " " << s2 << " " << w << " " << s3 << ".\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}