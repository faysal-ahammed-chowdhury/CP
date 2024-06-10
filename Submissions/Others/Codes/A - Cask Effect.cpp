#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  double a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if(n <= 2) {
    cout << fixed << setprecision(1) << a[0] << '\n';
    return 0;
  }
  double second_min = a[1];
  double max_val = a[n - 1];
  double min_val = a[0];
  double ans = min(second_min, (max_val + min_val) / 2.0);
  cout << fixed << setprecision(1) << ans << '\n';


  return 0;
}