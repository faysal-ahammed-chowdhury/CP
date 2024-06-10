#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int sum  = 0;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    sum += x;
  }
  bool ans = sum % 2 == 0;
  if(ans) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
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