//TIMING: 4:40
5 1 5
1 2 7
1 4 2
2 4 2
2 3 1
3 5 5
4 2 3
4 3 8
4 5 5
5 3 4
#include <bits/stdc++.h>
#define MAX 10000
#define INF 1<<30
using namespace std;
struct cmp{
    operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
int n,o,dest,a,b,c;
vector< int > d(MAX, INF);
vector< bool > v(MAX, false);
vector< int > p(MAX);
priority_queue< pair<int,int>, vector< pair<int,int> > , cmp> Q;
vector< vector< pair<int,int> > > lista(MAX);

void relax(int act, int ady, int peso){
    if(peso + d[act] < d[ady]){
        d[ady]=peso + d[act];
        p[ady]=act;
        Q.push(make_pair(ady, d[ady]));
    }
}

void dijkstra(){
    int act,ady,peso;
    Q.push(make_pair(o,0));
    d[o]=0;
    while(!Q.empty()){
        act = Q.top().first;
        Q.pop();

        if(v[act]) continue;
        v[act] = true;

        for(int i=0;i<lista[act].size();i++){
            ady = lista[act][i].first;
            peso = lista[act][i].second;
            if(!v[ady])
                relax(act,ady,peso);
        }
    }
}


void escribir(int a){
    if(p[a] != a)
        escribir(p[a]);
    cout << a << ' ';
}

int main(){
    ifstream fin("in.txt");
    fin >> n >> o >> dest;

    for(int i=1;i<=n;i++)
        p[i]=i;

    while(fin >> a >> b >> c){
        lista[a].push_back(make_pair(b,c));
        lista[b].push_back(make_pair(a,c));
    }

    dijkstra();

    escribir(dest);
}
