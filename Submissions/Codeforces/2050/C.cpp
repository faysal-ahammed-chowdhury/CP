#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  string s; cin >> s;
  int cnt2 = 0, cnt3 = 0, sum = 0;
  for (auto c : s) {
    sum += c - '0';
    if (c == '2') cnt2++;
    else if (c == '3') cnt3++;
  }

  if (sum % 9 == 0) {
    cout << "Yes\n";
    return;
  }

  cnt2 = min(20ll, cnt2);
  cnt3 = min(20ll, cnt3);

  int need = 9 - (sum % 9);
  for (int i = 0; i <= cnt2; i++) {
    for (int j = 0; j <= cnt3; j++) {
      if ((((i * 2) + (j * 6)) % 9) == need) {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}