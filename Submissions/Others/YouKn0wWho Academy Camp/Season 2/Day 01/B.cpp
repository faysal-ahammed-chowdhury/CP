#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    int c = s[i - 1];
    if (i & 1) ok &= c >= 'a' and c <= 'z';
    else ok &= c >= 'A' and c <= 'Z';
  }

  if (ok) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}