#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int s, d, k; cin >> s >> d >> k;
  int bun = s * 2 + d * 2;
  int patties = s + d * 2;
  int bun_need = k + 1;
  int patties_need = k;
  if(bun >= bun_need && patties >= patties_need) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1, cs = 0;
  cin >> t;
  while(t--) {
    cout << "Case #" << ++cs << ": ";
    solve();
  }

  return 0;
}