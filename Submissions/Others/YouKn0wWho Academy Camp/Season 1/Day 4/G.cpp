#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string a, b; cin >> a >> b;
  long long ans = 0, cnt = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] < b[i]) {
      int right = n - i - 1;
      ans++;
      ans += right;
      ans += cnt;
      ans += (cnt * right);
      cnt = 0;
    }
    else if(a[i] == b[i]) {
      cnt++;
    }
    else {
      cnt = 0;
    }
  }
  cout << ans << '\n';

  return 0;
}