#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long long sum = 0;
  int one_cnt = 0;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if(a[i] == 1) one_cnt++;
  }
  if(n == 1) {
    cout << "NO\n";
    return;
  }
  if((sum / n > 1)) {
    cout << "YES\n";
    return;
  }

  long long cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += a[i] - 1;
  }
  if(one_cnt <= cnt) {
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