#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

char not_this(char c) {
  if(c == 'R') return 'G';
  if(c == 'G') return 'B';
  return 'G';
}

char not_this_two(char c1, char c2) {
  if(c2 == 'A') {
    if(c1 == 'R') return 'G';
    if(c1 == 'G') return 'B';
    return 'G';
  }
  if((c1 == 'R' && c2 == 'G') || (c1 == 'G' && c2 == 'R')) return 'B';
  if((c1 == 'R' && c2 == 'B') || (c1 == 'B' && c2 == 'R')) return 'G';
  return 'R';
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<pair<int, int>> v;
  int start = 0, end = 0;
  for(int i = 1; i < n; i++) {
    if(s[i] != s[i - 1]) {
      end = i - 1;
      if(start != end) {
        v.push_back({start, end});
      }
      start = i;
    }
    else {
      end = i;
    }
  }

  if(start != n - 1) {
    v.push_back({start, n - 1});
  }

  int ans = 0;
  for(auto i: v) {
    // cout << i.first << ' ' << i.second << '\n';
    int len = i.second - i.first + 1;
    ans += len / 2;
    for(int j = i.first + 1; j < i.second; j += 2) {
      s[j] = not_this(s[j]);
    }
    if(len % 2 == 0) {
      char c;
      if(i.second + 1 < n) c = s[i.second + 1];
      else c = 'A';
      s[i.second] = not_this_two(s[i.second], c);
    }
  } 

  cout << ans << '\n';
  cout << s << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while(t--) {
    solve();
  }

  return 0;
}