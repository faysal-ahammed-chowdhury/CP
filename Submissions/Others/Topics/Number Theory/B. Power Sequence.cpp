#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAX = 1e14;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  ll ans = MAX;
  for(int c = 1; ; c++) {
    ll op = 0, pw = 1;
    for(int i = 0; i < n; i++) {
      op += (abs(a[i] - pw));
      pw *= c;
      if(pw > MAX) break;
      if(op > MAX) break;
    }
    if(pw > MAX) break;
    if(op > MAX) break;
    ans = min(ans, op);
  }

  cout << ans << '\n';

  return 0;
}