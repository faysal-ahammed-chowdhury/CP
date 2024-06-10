#include <bits/stdc++.h>
using namespace std;

int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  int a, b, c; cin >> a >> b >> c;
  if((a + b + c) % 3 == 0) {
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