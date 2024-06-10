#include <bits/stdc++.h>
using namespace std;

int first_half_sum(string s) {
  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    ans += s[i] - '0';
  }
  return ans;
}

int last_half_sum(string s) {
  int n = s.size();
  int ans = 0;
  for (int i = n / 2; i < n; i++) {
    ans += s[i] - '0';
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }


  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      string x = s[i] + s[j];
      if (x.length() % 2 == 0) {
        int sum1 = first_half_sum(x);
        int sum2 = last_half_sum(x);
        if (sum1 == sum2) ans++;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}