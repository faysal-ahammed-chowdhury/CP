#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  string x = s;
  reverse(s.begin(), s.end());
  s += '0';
  int n = s.size();
  char mx = 0;
  int idx;
  for(int i = 0; i < n; i++) {
    if(s[i] > mx) {
      idx = i;
      mx = s[i];
    }
  }
  int last = -1;
  for(int i = idx + 1; i <= n; i++) {
    if(s[i - 1] >= '5') {
      last = i;
      s[i]++;
    }
  }
  if(last == -1) {
    cout << x << '\n';
    return;
  }
  for(int i = n - 2; i > last; i--) {
    cout << s[i];
  }
  cout << s[last];
  for(int i = last; i >= 1; i--) {
    cout << 0;
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