#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int src;
    int dst;
    int wght;
    int indx;
};

    bool sortEdges(Edge e1 , Edge e2)
{
    return e1.wght<e2.wght;
}

struct Path
{
    int node;
    int edge;
};
    int  * parent;
    int * sizer ;
     Edge * edges ;
    int state [1000020];
    int es;
    int vs;
    int timer;
  vector<Path> spanTree[1000020];
    int  tin[1000020];
    int  low[1000020];

    void createGraph(int n[],Edge  e[],int s[],int vs , int es) {
        edges = e;
        parent = n;
        sizer = s;

    }


    int find(int p) {

        int root = p;
        while (root != parent[root])
            root = parent[root];
        while (p != root) {
            int newp = parent[p];
            parent[p] = root;
            p = newp;
        }
        return root;
    }


     bool connected(int p, int q) {
        return find(p) == find(q);
    }



     void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

      /// make smaller root point to larger one
        if (sizer[rootP] < sizer[rootQ]) {
            parent[rootP] = rootQ;
            sizer[rootQ] += sizer[rootP];
        }
        else {
            parent[rootQ] = rootP;
            sizer[rootP] += sizer[rootQ];
        }

    }

void dfs(int node, int p) {
	low[node] = tin[node] = ++timer;

	for(int i=0; i<spanTree[node].size();i++) {
        Path  u = spanTree[node].at(i);
		if(u.edge==p) continue;
		if(tin[u.node]==-1) {
			dfs(u.node, u.edge);
			if(low[u.node]>tin[node]) state[u.edge] = 1;
			low[node] = min(low[node], low[u.node]);
		} else {
			low[node] = min(low[node], tin[u.node]);
		}
	}
}

    void solve(int l , int r)
    {
        for(int i=l;i<=r;i++) {
		int u = find(edges[i].src);
		int v = find(edges[i].dst);
        spanTree[u].clear();
		spanTree[v].clear();
		tin[u] = tin[v] = -1;
		low[u] = low[v] = -1;
	}
	timer = 0;
		for(int i=l;i<=r;i++) {
		int u = find(edges[i].src);
		int v = find(edges[i].dst);
		if(u==v) {
			state[edges[i].indx] = 0;
		} else {
			state[edges[i].indx] = 2;
			Path p1,p2;
			p1.edge=edges[i].indx;
			p2.edge=edges[i].indx;
			p1.node=u;
			p2.node=v;
			spanTree[u].push_back(p2);
			spanTree[v].push_back(p1);
		} }
    	for(int i=l;i<=r;i++) {
		int u = find(edges[i].src);
		int v = find(edges[i].dst);
		if(tin[u]==-1) dfs(u, -1);
		else if(tin[v]==-1) dfs(v, -1);
	}
	for(int i=l;i<=r;i++) Union(find(edges[i].src), find(edges[i].dst));
    }

    void getInfo()
    {
        sort(edges,edges+es,sortEdges);
        for(int i=0;i<es;i++) {
		int j = i;
		while(j<es && edges[j].wght==edges[i].wght) j++;
		j--;
		solve(i, j); // solve for all edges of same weight simultaneously
		i = j;
	}

		for(int i=0;i<es;i++) {
		if(state[i]==0) cout << "none";
		else if(state[i]==1) cout << "any";
		else cout << "at least one";
		cout << "\n";
	}

    }








int main()
{
   int vertexes;
   int * v;
   int * s;
   Edge * e;
   int m,n,n1,n2,n3;
   cin>>n>>m;
   e = new Edge[m];
   v = new int[n+1];
   s = new int[n+1];

   es=m;
   vs=n;
   for(int i=0;i<n+1;i++)
   {v[i]=i;
    s[i]=1;}
   for(int i=0;i<m;i++)
   {
    cin>>n1>>n2>>n3;
    Edge t;
    t.src=n1;
    t.dst=n2;
    t.wght=n3;
    t.indx=i;

    e[i]=t;
   }
   createGraph(v,e,s,n,m);
   getInfo();




}
