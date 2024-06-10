#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

bool check(long double n) {
  string s = to_string(n);
  int len = s.length();
  if(s[len - 5] == '0' && s[len - 6] == '0') return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  char c; long double amount; cin >> c >> amount;
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    long double x; cin >> c >> x;
    amount += x;
    if(check(amount)) {
      cnt++;
    }
  }

  cout << cnt << '\n';

  return 0;
}