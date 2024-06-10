#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string t1; cin >> t1;
  set<string> se1, se2;
  vector<pair<string, string>> players;
  set<pair<string, string>> players_se;
  for (int i = 1; i <= 5; i++) {
    string x; cin >> x;
    se1.insert(x);
    players.push_back({x, t1});
    players_se.insert({x, t1});
  }

  string t2; cin >> t2;
  for (int i = 1; i <= 5; i++) {
    string x; cin >> x;
    se2.insert(x);
    players.push_back({x, t2});
    players_se.insert({x, t2});
  }

  int q; cin >> q;
  map<pair<string, string>, int> mp;
  while (q--) {
    string x, t; cin >> x >> t >> x;
    if (x == "scored") {
      int n; cin >> n;
      if (t == t1) {
        for (auto s : se1) {
          mp[ {s, t1}] += n;
        }
        for (auto s : se2) {
          mp[ {s, t2}] -= n;
        }
      }
      else {
        for (auto s : se1) {
          mp[ {s, t1}] -= n;
        }
        for (auto s : se2) {
          mp[ {s, t2}] += n;
        }
      }
    }
    else {
      string p1, x, p2; cin >> p1 >> x >> p2;
      if (players_se.find({p2, t}) == players_se.end()) {
        players.push_back({p2, t});
        players_se.insert({p2, t});
      }
      if (t == t1) {
        se1.erase(p1);
        se1.insert(p2);
      }
      else {
        se2.erase(p1);
        se2.insert(p2);
      }
    }
  }

  for (auto [p, t] : players) {
    cout << p << " (" << t << ") ";
    int point = mp[{p, t}];
    if (point > 0) {
      cout << '+';
    }
    cout << point << '\n';
  }

  return 0;
}