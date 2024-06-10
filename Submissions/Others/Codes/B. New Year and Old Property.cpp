#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long a, b; cin >> a >> b;
  int msb = __lg(b);
  long long now = 0;
  for (int i = 0; i <= msb; i++) {
    now += (1ll << i); // set all bit
  }
  long long minus = 1, ans = 0;
  while(now - minus >= a) {
    if(((now - minus) & (now - minus + 1)) == 0) {
      now = now - minus;
      minus = 1;
    }
    if(now - minus >= a && now - minus <= b) {
      ans++;
    }
    minus *= 2;
  }
  cout << ans << '\n';

  return 0;
}