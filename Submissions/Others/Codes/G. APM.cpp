#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int N = 105;
map<pair<string, string>, vector<pair<string, string>>> g;
bool ans;

void dfs(pair<string, string> u, map<string, string> &mp, pair<string, string> p, bool first) {
  if (u == p and !first) {
    return;
  }
  if (mp.find(u.first) != mp.end() and mp[u.first] != u.second) {
    ans = false;
    return;
  }
  else {
    mp[u.first] = (u.second);
  }
  for (auto v : g[u]) {
    dfs(v, mp, p, 0);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  set<string> se;
  for (int i = 1; i <= n; i++) {
    string p; cin >> p;
    string name = "", version = "";
    int j = 0;
    for (j = 0; j < p.length(); j++) {
      if (p[j] == ':') {
        j++;
        break;
      }
      name += p[j];
    }
    for (; j < p.length(); j++) {
      version += p[j];
    }

    bool ok = true;
    int m; cin >> m;
    vector<string> v;
    for (int j = 0; j < m; j++) {
      string s; cin >> s;
      v.push_back(s);
      if (se.find(s) == se.end()) {
        ok = false;
        break;
      }
    }

    if (ok) {
      map<string, string> mp;
      for (auto x : v) {
        string n = "", ver = "";
        int j = 0;
        for (j = 0; j < x.length(); j++) {
          if (p[j] == ':') {
            j++;
            break;
          }
          n += x[j];
        }
        for (; j < p.length(); j++) {
          ver += x[j];
        }
        g[ {name, version}].push_back({n, ver});
      }

      ans = true;
      dfs({name, version}, mp, {name, version}, 1);
      ok = ans;
    }

    if (ok) {
      cout << "Request " << i << ": OK\n";
      se.insert(p);
      for (auto x : se) {
        cout << x << '\n';
      }
    }
    else {
      cout << "Request " << i << ": ERROR\n";
      g.erase({name, version});
    }
  }

  return 0;
}