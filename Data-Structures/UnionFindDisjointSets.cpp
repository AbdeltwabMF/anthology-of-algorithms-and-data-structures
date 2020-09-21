#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 2e6 + 9;

void File() {
    freopen("input.in", "r", stdin);
}

/**
 	Applications
 1. Connected components in a graph.
 2. Search for connected components in an image.
 3. Store additional information for each set.
 4. Compress jumps along a segment / Painting subarrays offline.
 5. Support distances up to representative.
 6. Support the parity of the path length / Checking bipartiteness online.
 7. Offline RMQ (range minimum query) in O(α(n)) on average / Arpa's trick.
 8. Offline LCA (lowest common ancestor in a tree) in O(α(n)) on average.
 9. Minimum spanning tree - Kruskal with Disjoint Set Union.
**/

class UnionFind
{
	public:
		UnionFind(size_t n) {
			
			assert(n > 0);
			disjoint_sets = sz = n;
			
			par = vector <int> (n + 1);
			siz = vector <int> (n + 1);
			
			for(size_t i = 0; i <= n; ++i) 
			{
				par[i] = i;
				siz[i] = 1;
			} 
		}
		
		int find_set(int u) {
			
			// find representative (leader) item
			int leader;
			for(leader = u; leader != par[leader]; leader = par[leader]);
			
			// path compression
			for(int next = par[u]; u != leader; next = par[next]) {
				par[u] = leader;
				u = next;
			}
			
			return leader;
		}
		
		bool same_set(int u, int v) {
			return find_set(u) == find_set(v);
		}
		/**
		union by size
		if union operation success return true otherwise return false
		**/
		bool union_set(int u, int v) {
		
			if(same_set(u, v)) return false;
			
			int x = find_set(u);
			int y = find_set(v);
			
			if(siz[x] < siz[y]) swap(x, y);
				
			par[y] = x;
			siz[x] += siz[y];
			
			--disjoint_sets;
				
			return true;
		}

		int size_of_set(int u) {
			return siz[find_set(u)];
		}
	
		int components() {
			return disjoint_sets;
		}
		
		size_t size() {
			return sz;
		}
					
	private:
		vector <int> par;
		vector <int> siz;
		int disjoint_sets;
		size_t sz;
};

/** Example : Minimum spanning tree - Kruskal. **/

struct edge
{
	int from, to, weight;
	
	edge () {}
	edge (int f, int t, int w) : from(f), to(t), weight(w) {}
	
	bool operator < (const edge & other) const 
	{
		return weight > other.weight;
	} 
};

int n, m;
vector <edge> edges;

pair <vector <edge>, int> Kruskal()
{
	vector <edge> mst;
	int cost = 0;

	UnionFind uf = UnionFind(n);
	priority_queue <edge> pq; // greater at top by default
	
	for(int i = 0; i < m; ++i)
		pq.push(edges[i]);
	
	
	while(pq.size())
	{
		edge e = pq.top(); pq.pop();
		if(uf.union_set(e.from, e.to))
		{
			cost += e.weight;
			mst.push_back(e);
		}
	}
	
	return mst.size() == n - 1 ? make_pair(mst, cost) : make_pair(vector <edge> (), -(int)1e9);	
}

int main()
{
	File();
	
	cin >> n >> m;
	edges = vector <edge> (m);

	for(int i = 0; i < m; ++i)
	{
		cin >> edges[i].from >> edges[i].to >> edges[i].weight; 
	}
	
	vector <edge> mstTree;
	int cost;
	
	tie(mstTree, cost) = Kruskal();

	for(int i = 0; i < mstTree.size(); ++i)
		cout << mstTree[i].from << " " << mstTree[i].to << " " << mstTree[i].weight << endl;		

	cout << "cost = " << cost << endl;
}

