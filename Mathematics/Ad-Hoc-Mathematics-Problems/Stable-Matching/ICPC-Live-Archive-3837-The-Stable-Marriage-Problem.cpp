#include <bits/stdc++.h>

#define endl    '\n'

using namespace std;

const int N = 40;
int n;
struct woman {
  int husband, pref_list[N];
  char name;
  woman () {
    memset(pref_list, 0x00, sizeof pref_list);
    husband = 0;
    name = '\0';
  }
};

struct man {
  int next_proposal, pref_list[N];
  char name;
  man () {
    memset(pref_list, 0x00, sizeof pref_list);
    next_proposal = 1;
    name = '\0';
  }
};

char u, v, why;
map <char, int> mp;
queue <int> single;
vector < array <char, 2> > matching_list;
man men[N];
woman women[N];

void _clear() {
  mp.clear();
  single = queue <int> ();
  matching_list = vector < array <char, 2> > ();
}

void Solve()
{
  cin >> n;
  _clear();

  for(int i = 1; i <= n; ++i) {
    cin >> u, mp[u] = i;
    men[i] = man();
    men[i].name = u;
    single.push(i);
  }
  for(int i = 1; i <= n; ++i) {
    cin >> v, mp[v] = i;
    women[i] = woman();
    women[i].name = v;
  }
  for(int i = 1; i <= n; ++i) {
    cin >> u >> why;
    for(int j = 1; j <= n; ++j) {
      cin >> v;
      men[mp[u]].pref_list[j] = mp[v];
    }
  }
  for(int i = 1; i <= n; ++i) {
    cin >> v >> why;
    for(int j = 1; j <= n; ++j) {
      cin >> u;
      women[mp[v]].pref_list[mp[u]] = j;
    }
  }

  int cur_man, cur_woman, ex_man;
  while(!single.empty()) {
    cur_man = single.front();
    cur_woman = men[cur_man].pref_list[men[cur_man].next_proposal];

    if(women[cur_woman].husband == 0) {
      women[cur_woman].husband = cur_man;
      single.pop();
    } else if(women[cur_woman].pref_list[cur_man] < women[cur_woman].pref_list[women[cur_woman].husband]) {
      ex_man = women[cur_woman].husband;
      women[cur_woman].husband = cur_man;
      single.pop();
      single.push(ex_man);;
    }
    ++men[cur_man].next_proposal;
  }

  for(int i = 1; i <= n; ++i)
    matching_list.push_back({men[women[i].husband].name, women[i].name});

  sort(matching_list.begin(), matching_list.end());

  for(array <char, 2> p : matching_list)
    cout << p[0] << " " << p[1] << endl;
}

void MultiTest(bool Tests = 0)
{
  int tc = 1; (Tests) && (cin >> tc);
  for(int i = 1; i <= tc; ++i) {
    if(i > 1) cout << endl;
    Solve();
  }
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
  MultiTest(1);
}

