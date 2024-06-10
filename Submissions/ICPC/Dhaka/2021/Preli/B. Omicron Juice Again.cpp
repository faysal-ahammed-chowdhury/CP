#include <bits/stdc++.h>
using namespace std;

int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  int a, b, c, k; cin >> a >> b >> c >> k;
  int sum = (a + b + c);
  if(sum % 3 != 0) {
    cout << "Fight\n";
    return;
  }
  int avg = sum / 3;
  if(abs(avg - a) % k == 0 and abs(avg - b) % k == 0 and abs(avg - c) % k == 0) {
    cout << "Peaceful\n";
  }
  else {
    cout << "Fight\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}