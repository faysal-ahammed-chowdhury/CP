#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (s[i] != s[i - 1]) cnt++;
  }  

  cout << cnt - 1 << '\n';

  return 0;
}