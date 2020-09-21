#include "bits/stdc++.h"

using namespace std;

const int N = 5e2 + 9;

/**----------------->>  Quality Over Quantity  <<----------------**/

int n, u, v, ar[N << 1];
queue <int> single;
vector < array <int, 2> > matching_list;

struct woman
{
    int husband, pref_list[N];
    woman ()
    {
        memset(pref_list, 0x00, (n + 4) << 2);
        husband = 0;
    }
};

struct man
{
    int next_proposal, pref_list[N];
    man ()
    {
         memset(pref_list, 0x00, (n + 4) << 2);
         next_proposal = 1;
    }
};

man men[N];
woman women[N];

void Solve()
{
    cin >> n;
    single = queue <int> ();
    matching_list = vector < array <int, 2> > ();

    for(int i = 1; i <= n; ++i)
    {
        cin >> v;
        women[v] = woman();
        for(int j = 1; j <= n; ++j)
        {
            cin >> u;
            women[v].pref_list[u] = j;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        cin >> u;
        men[u] = man();
        single.push(u);
        for(int j = 1; j <= n; ++j)
        {
            cin >> v;
            men[u].pref_list[j] = v;
        }
    }

    int cur_man, cur_woman, ex_man;
    while(!single.empty())
    {
        cur_man = single.front();
        cur_woman = men[cur_man].pref_list[men[cur_man].next_proposal];

        if(women[cur_woman].husband == 0)
        {
            women[cur_woman].husband = cur_man;
            single.pop();
        }
        else if(women[cur_woman].pref_list[cur_man] < women[cur_woman].pref_list[women[cur_woman].husband])
        {
            ex_man = women[cur_woman].husband;
            women[cur_woman].husband = cur_man;
            single.pop();
            single.push(ex_man);
        }
        ++men[cur_man].next_proposal;
    }

    for(int i = 1; i <= n; ++i)
        matching_list.push_back({women[i].husband, i});

    sort(matching_list.begin(), matching_list.end());

    for(array <int, 2> p : matching_list)
        cout << p[0] << " " << p[1] << endl;
}

void MultiTest(bool Tests = 0)
{
    int tc = 1; (Tests) && (cin >> tc);
    for(int i = 1; i <= tc; ++i)
        Solve();
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
	MultiTest(1);
}
