#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2) {
  return s1.length() < s2.length();
}

int get_sum(string s, int start, int end) {
  int ans = 0;
  for (int i = start; i <= end; i++) {
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

  sort(s + 1, s + 1 + n, cmp);
  map<int, map<int, int>> mp; // len -> sum, cnt
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = s[i].length();
    for (int j = x; j > 0; j -= 2) {
      int total_len = x + j;
      int per_len = total_len / 2;
      int donate_len = x - per_len;
      int my_sum_first = get_sum(s[i], 0, per_len - 1);
      int my_sum_last = get_sum(s[i], donate_len, x - 1);
      int donate_sum_first = get_sum(s[i], 0, donate_len - 1);
      int donate_sum_last = get_sum(s[i], x - donate_len, x - 1);
      int need1 = (my_sum_last - donate_sum_first);
      int need2 = (my_sum_first - donate_sum_last);
      ans += mp[j][need1];
      ans += mp[j][need2];
    }
    mp[x][get_sum(s[i], 0, x - 1)]++;
  }

  cout << ans + n << '\n';

  return 0;
}