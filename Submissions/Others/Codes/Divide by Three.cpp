#include <bits/stdc++.h>
using namespace std;

string s;
int n;

pair<int, int> get_indices(int num) {
  int idx1 = -1, idx2 = -1;
  bool is_first = true;
  for (int i = n - 1; i >= 0; i--) {
    int x = s[i] - '0';
    if ((x % 3) == num) {
      if (is_first) {
        idx1 = i;
        is_first = false;
      }
      else {
        idx2 = i;
        break;
      }
    }
  }
  return make_pair(idx1, idx2);
}

string get_ans(int idx1, int idx2) {
  string ans = "";
  bool has_started = false;
  bool has_zero = false;
  for (int i = 0; i < n; i++) {
    int x = s[i] - '0';
    if (x == 0) has_zero = true;
    if (i == idx1 or i == idx2) continue;
    if (x == 0 and !has_started) continue;
    ans += s[i];
    has_started = true;
  }
  if (ans == "" and has_zero) ans = "0"; 
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = s.size();
  map<int, int> mp;
  int rem = 0;
  for (auto c : s) {
    int x = c - '0';
    rem = (rem + (x % 3)) % 3;
    mp[x % 3]++;
  }

  if (rem == 0) {
    cout << s << '\n';
    return 0;
  }
  else if (rem == 1 and (mp[1] >= 1 or mp[2] >= 2)) {
    string ans1 = "", ans2 = "";
    if (mp[1] >= 1 and n != 1) {
      auto [idx1, idx2] = get_indices(1);
      idx2 = -1;
      ans1 = get_ans(idx1, idx2);
    }
    if (mp[2] >= 2 and n != 2) {
      auto [idx1, idx2] = get_indices(2);
      ans2 = get_ans(idx1, idx2);
    }
    if (max(ans1.length(), ans2.length()) != 0) {
      cout << (ans1.size() > ans2.size() ? ans1 : ans2) << '\n';
      return 0;
    }
  }
  else if (rem == 2 and (mp[2] >= 1 or mp[1] >= 2)) {
    string ans1 = "", ans2 = "";
    if (mp[1] >= 2 and n != 2) {
      auto [idx1, idx2] = get_indices(1);
      ans1 = get_ans(idx1, idx2);
    }
    if (mp[2] >= 1 and n != 1) {
      auto [idx1, idx2] = get_indices(2);
      idx2 = -1;
      ans2 = get_ans(idx1, idx2);
    }
    if (max(ans1.length(), ans2.length()) != 0) {
      cout << (ans1.size() > ans2.size() ? ans1 : ans2) << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';

  return 0;
}