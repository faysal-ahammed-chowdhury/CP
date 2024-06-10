#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int str_to_int(string s) {
  int n = 0;
  for(auto i: s) {
    n = n * 10 + (i - '0');
  }
  return n;
}

string int_to_str(int n) {
  stringstream ss;
  ss << n;
  string s; ss >> s;
  return s;
}

string get_text(string &s) {
  int len = s.length();
  int i = len - 1;
  while(isdigit(s[i])) {
    i--;
  }
  string str = "";
  for(int j = 0; j <= i; j++) {
    str += s[j];
  }
  return str;
}

int get_num(string &s) {
  int len = s.length();
  int i = len - 1;
  string str = "";
  while(isdigit(s[i])) {
    str += s[i];
    i--;
  }
  reverse(str.begin(), str.end());
  return str_to_int(str);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<string, priority_queue<int>> mp;
  set<string> se;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    string text = get_text(s);
    int num = s == text ? -1 : get_num(s);
    if(mp.find(s) == mp.end()) {
      se.insert(s);
      mp[text].push(num);
      cout << s << '\n';
    }
    else {

    }
  }
        
  return 0;
}