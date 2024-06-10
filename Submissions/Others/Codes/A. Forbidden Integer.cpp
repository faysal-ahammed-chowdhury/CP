#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;


void solve() {
  int n, k, x; cin >> n >> k >> x;
  if(x != 1) {
    cout << "YES\n";
    cout << n << '\n';
    for(int i = 1; i <= n; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
    return;
  }

  if(k == 1) {
    cout << "NO\n";
    return;
  }
  if(k == 2) {
    if(n % 2 == 1) {
      cout << "NO\n";
      return;
    }
  }
  if(n % 2 == 0) {
    cout << "YES\n";
    int x = n / 2;
    cout << x << "\n";
    for(int i = 1; i <= x; i++) {
      cout << 2 << ' ';
    }
    cout << '\n';
  }
  else {
    cout << "YES\n";
    int x = (n - 3) / 2;
    cout << x + 1 << "\n";
    for(int i = 1; i <= x; i++) {
      cout << 2 << ' ';
    }
    cout << "3\n";
  }
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