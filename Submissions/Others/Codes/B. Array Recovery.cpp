#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  int a[n], d[n];
  for(int i = 0; i < n; i++) {
    cin >> d[i];
  }
  a[0] = d[0];
  for(int i = 1; i < n; i++) {
    a[i] = a[i - 1] + d[i];
    if(a[i - 1] - d[i] >= 0 && a[i - 1] + d[i] >= 0 && a[i - 1] - d[i] != a[i - 1] + d[i]) {
      cout << "-1\n";
      return;
    }
  }
  for(int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
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