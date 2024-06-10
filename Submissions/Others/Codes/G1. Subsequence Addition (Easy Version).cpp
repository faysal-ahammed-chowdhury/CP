#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  for(int i = 0; i < n; i ++) {
    if(a[i] == 1) continue;
    int val = a[i];
    int x = 0;
    for(int j = i + 1; j < n; j++) {
      if(x + a[j] <= val) {
        x += a[j];
      }
    }
    if(x != val) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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