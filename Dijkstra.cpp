#include <bits/stdc++.h>
#define int64 long long
#define pb push_back
#define mp make_pair
#define INF numeric_limits<int>::max()
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
vector< vector< pair<int,int> > > a;
priority_queue< pair<int,int> > h; //daca nu vrei sa bagi distantele negative in heap poti sa declari asa: priority_queue< int , vector<int> , greater<int> > h;
vector<int> dist;
int main()
{
    // citire
 
    int n,m;
    in>>n>>m;
    a=vector< vector< pair<int,int> > > (n+1);
    dist=vector<int> (n+1,INF);//toate distantele sunt infinit initial
    for(;m;m--)
    {
        int x,y,z;
        in>>x>>y>>z;
        a[x].pb(mp(y,z));
        //a[y].pb(mp(x,z)); //in caz ca graful e orientat
    }
 
    //algoritm
 
    dist[1]=0;
    h.push(mp(-dist[1],1));
    while(!h.empty())//cat timp heap-ul nu e gol
    {
        int x=h.top().second;
        h.pop();
        for(vector< pair<int,int> >::iterator i=a[x].begin();i!=a[x].end();i++)
        if(dist[x] + i->second < dist[i->first])
        {
            dist[i->first]=dist[x] + i->second;
            h.push(mp(-dist[i->first],i->first));//introduc distantele negative pt ca priority_queue e max heap
 
        }
    }
 
    //afisez distantele
 
    for(int i=2;i<=n;i++)
    {
        if(dist[i]==INF)
            dist[i]=0;
        out<<dist[i]<<' ';
    }
    return 0;
}