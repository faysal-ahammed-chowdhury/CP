#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int must = 0, optional = 0;
  int l = 0, r = n - 1;
  while(l < r) {
    if(s[l] != s[r]) {
      must++;
    }
    else {
      optional += 2;
    }
    l++, r--;
  }
  bool flag = false;
  if(n & 1) flag = true;
  int mx = optional + must + flag;
  char ans[n + 5];
  memset(ans, '0', sizeof(ans));
  for(int i = must; i <= mx;) {
    ans[i] = '1';
    if(flag) i++;
    else i += 2;
  }
  for(int i = 0; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}