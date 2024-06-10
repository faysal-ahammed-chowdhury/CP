#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
  if(l1 != l2) {
    cout << l1 << ' ' << l2 << '\n';
    return;
  }

  if(r1 != r2) {
    cout << r1 << ' ' << r2 << '\n';
    return;
  }

  cout << l1 << ' ' << r2 << '\n';
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