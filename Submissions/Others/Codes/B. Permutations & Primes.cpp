#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  if(n == 1) {
    cout << 1 << '\n';
    return;
  }
  if(n == 2) {
    cout << 1 << ' ' << 2 << '\n';
    return;
  }

  int ans[n + 1];
  int mid = (1 + n) / 2;
  ans[1] = 2;
  ans[mid] = 1;
  ans[n] = 3;
  int start = 4;
  for(int i = 2; i < mid; i++) {
    ans[i] = start++;
  }
  for(int i = mid + 1; i < n; i++) {
    ans[i] = start++;
  }

  for(int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
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