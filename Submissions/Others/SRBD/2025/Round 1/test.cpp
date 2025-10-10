#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(int h, int m) {
  string a = to_string(h);
  string b = to_string(m);
  if (a.size() == 1) a = '0' + a;
  if (b.size() == 1) b = '0' + b;
  return a[0] == a[1] and b[0] == b[1] and a[1] == b[1];
}

void next(int &h, int &m) {
  m++;
  if (m == 60) {
    h++;
    if (h == 24) h = 0;
    m = 0;
  }
}

void solve() {
  string s; cin >> s;
  int hh = (s[0] - '0') * 10 + (s[1] - '0');
  int mm = (s[3] - '0') * 10 + (s[4] - '0');

  while (!ok(hh, mm)) {
    next(hh, mm);
  }

  string a = to_string(hh);
  string b = to_string(mm);
  if (a.size() == 1) a = '0' + a;
  if (b.size() == 1) b = '0' + b;
  cout << a << ':' << b << '\n';
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