#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  string r = s;
  reverse(s.begin(), s.end());

  map<char, vector<int>> mp1, mp2;
  for(int i = 0; i < n; i++) {
    mp1[s[i]].push_back(i);
  }
  for(int i = 0; i < n; i++) {
    mp2[r[i]].push_back(i);
  }

  int p[n];
  for(auto i: mp1) {
    for(int j = 0; j < i.second.size(); j++) {
      p[i.second[j]] = mp2[i.first][j];
    }
  }

  o_set<int> se;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += se.order_of_key(p[i]);
    se.insert(p[i]);
  }
  cout << ans << '\n';

  return 0;
}