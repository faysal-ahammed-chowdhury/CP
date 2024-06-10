#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x, y; cin >> n >> x >> y;
  string s; cin >> s;
  string rem = "1", divisor = "1";
  for(int i = 1; i <= x; i++) {
    divisor += '0';
  }
  for(int i = 1; i <= y; i++) {
    rem += '0';
  }
  int len_rem = rem.size(), div_len = divisor.size();
  int ans = 0;
  for(int i = n - 1, j = len_rem - 1; i >= (n - 1 - y); i--, j--) {
    if(s[i] != rem[j]) {
      ans++;
    }
  }
  for(int i = (n - 2 - y), j = (div_len - 2 - y); i > (n - 1 - x); i--, j--) {
    if(s[i] != divisor[j]) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}