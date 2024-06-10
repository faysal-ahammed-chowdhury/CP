#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int unique_number_count[1009][1009];
int last_index[1009];

char func(int unique) {
  return char(unique + 'a');
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  for(int i = 0; i < n; i++) {
    set<char> se;
    for(int j = i + 1; j < n; j++) {
      se.insert(s[j]);
      unique_number_count[i][j] += (int)se.size();
    }
  }

  // for(int i = 0; i < n; i++) {
  //   for(int j = i; j < n; j++) {
  //     cout << i << '-' << j << ": " << unique_number_count[i][j] << '\n';
  //   }
  // }

  string ans = "";
  for(int k = 1; k <= n; k++) {
    string sub = s.substr(0, k);
    int len = sub.length();
    for(int i = 0; i < len; i++) {
      int x = sub[i] - 'a';
      last_index[x] = i;
    }

    string new_str = "";
    for(int i = 0; i < len; i++) {
      int x = sub[i] - 'a';
      new_str += func(unique_number_count[last_index[x]][k - 1]);
    }
    ans = max(ans, new_str);
  }
 
  cout << ans << '\n';

  return 0;
}