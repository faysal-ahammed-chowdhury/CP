#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  if(a + b >= 10 || a + c >= 10 || b + c >= 10) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}