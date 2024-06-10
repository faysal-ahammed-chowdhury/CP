#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int time[n + 1], employee[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> employee[i] >> time[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int end = time[i] + 9, tmp = 0;
    for (int j = 1; j <= n; j++) {
      if (end < 24) {
        if (time[j] < end and time[j] >= time[i]) {
          tmp += employee[j];
        }
      }
      else {
        int x = end % 24;
        if (time[j] >= time[i] and time[j] < 24) {
          tmp += employee[j];
        }
        else if (time[j] < x) {
          tmp += employee[j];
        }
      }
    }
    ans = max(ans, tmp);
  }

  cout << ans << '\n';

  return 0;
}