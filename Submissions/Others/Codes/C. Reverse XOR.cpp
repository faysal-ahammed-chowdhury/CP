#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void convert(int n, string &s) {
  s = "";
  while (n > 0) {
    int last = n % 2;
    if (last == 1) s += '1';
    else s += '0';
    n /= 2;
  }
  reverse(s.begin(), s.end());
}

void solve() {
  int n; cin >> n;

  if (n == 0) {
    cout << "YES\n";
    return;
  }

  if (((n & (n - 1)) == 0)) {
    cout << "NO\n";
    return;
  }

  while (n > 0 and n % 2 == 0) n /= 2;
  string s;
  convert(n, s);

  int cnt = 0;
  for (auto c : s) {
    cnt += c == '1';
  }

  if (cnt & 1) {
    cout << "NO\n";
    return;
  }

  int l = 0, r = s.size() - 1;
  while (l <= r) {
    if (s[l] != s[r]) {
      cout << "NO\n";
      return;
    }
    l++, r--;
  }

  cout << "YES\n";
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