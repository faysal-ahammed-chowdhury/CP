#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

bool ok(string s, char ch) {
  int n = s.length();
  for(int i = 1; i < n; i++) {
    if(s[i] != ch) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; char ch; cin >> n >> ch;
    string s; cin >> s;
    s = 'a' + s; // 1 base index
    if(ok(s, ch)) {
      cout << 0 << '\n';
      continue;
    }
    bool flag = false;
    for(int i = 2; i <= n; i++) {
      int x = n / i, cnt = 0;
      for(int j = i; j <= n; j += i) {
        if(s[j] == ch) cnt++;
      }
      if(x == cnt) {
        cout << 1 << '\n';
        cout << i << '\n';
        flag = true;
        break;
      }
    }
    if(!flag) {
      cout << 2 << '\n';
      cout << n - 1 << ' ' << n << '\n';
    }
  }

  return 0;
}