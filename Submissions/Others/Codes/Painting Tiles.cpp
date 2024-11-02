#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  long long n; cin >> n;
  cout << "Case " << ++cs << ": ";
  if (n % 7 <= 1) cout << "Oh no, my eggs! :(\n";
  else cout << "No eggs for you! :D\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}