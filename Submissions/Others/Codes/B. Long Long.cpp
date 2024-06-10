#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  int a[n];
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += abs(a[i]);
  }
  int cnt = 0;
  bool last_neg = false;
  for(int i = 0; i < n; i++) {
    if(a[i] == 0) continue;
    if(a[i] < 0) {
      last_neg = true;
    }
    else if(last_neg == true) {
      cnt++;
      last_neg = false;
    }
  }
  if(last_neg == true) {
    cnt++;
  }
  cout << sum << ' ' << cnt << '\n';
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