#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  int cnt1 = 0, cnt0 = 0;
  for (auto c : s) {
    cnt0 += c == '0';
    cnt1 += c == '1';
  }

  int mn = min(cnt0, cnt1);
  mn += mn;

  cout << n - mn << '\n';

  return 0;
}