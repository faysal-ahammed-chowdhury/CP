#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2; cin >> s1 >> s2;
  int n = s1.length(), m = s2.length();
  if(n > m) {
    swap(n, m);
    swap(s1, s2);
  }
  int g = __gcd(n, m);
  set<int> se;
  for(int i = 1; i * i <= g; i++) {
    if(g % i == 0) {
      se.insert(i);
      se.insert(g / i);
    }
  }

  int ans = 0;
  for(auto i: se) {
    string sub = s1.substr(0, i);
    bool ok = true;
    string x = sub;
    int len = n / i;
    for(int j = 1; j < len; j++) {
      x += sub;
    }
    if(x != s1) ok = false;

    x = sub;
    len = m / i;
    for(int j = 1; j < len; j++) {
      x += sub;
    }
    if(x != s2) ok = false;

    if(ok) ans++;
  }

  cout << ans << '\n';

  return 0;
}