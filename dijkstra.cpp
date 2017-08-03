//TIMING: 5:32:12
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
    operator()(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
};
bool visitado[MAX];
int distancia[MAX];
int previo[MAX];
vector< vector< pair<int,int> > > lista(MAX);
priority_queue< pair<int,int>, vector< pair<int,int> >, cmp> Q;
int n,o,d,a,b,c;

void relax(int act, int ady, int peso){
    if(peso + distancia[act] < distancia[ady]){
        distancia[ady] = distancia[act] + peso;
        previo[ady] = act;
        Q.push(make_pair(ady, distancia[ady]));
    }
}

void dijkstra(){
    distancia[o]=0;
    Q.push(make_pair(o,0));
    int act,ady,peso;
    while(!Q.empty()){
        act = Q.top().first;
        Q.pop();

        if(visitado[act]) continue;
        visitado[act] = true;

        for(int i=0;i<lista[act].size();i++){
            ady = lista[act][i].first;
         peso= lista[act][i].second;
            if(!visitado[ady]) relax(act,ady,peso);
        }
    }
}

void escribir(int a) {
    if(previo[a] != a)
        escribir(previo[a]);
    cout << a << ' ';
}

void init(){
    for(int i=1;i<=n;i++){
        visitado[i] = false;
        distancia[i] = INF;
        previo[i] = i;
    }
}

int main(){
    ifstream fin("in.txt");
    fin >> n >> o >> d;

    init();

    while(fin >> a >> b >> c)
        lista[a].push_back(make_pair(b,c));

    dijkstra();

    escribir(d);
}
