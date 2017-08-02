//Input
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
using namespace std;

struct cmp{
    bool operator()(const pair<int,int> a, const pair<int,int> b){
        return a.second > b.second;
    }
};

#define MAX 5000
#define INF 1<<30

int n,m,o,d;
int previo[MAX];
int distancia[MAX];
bool visitado[MAX];
vector< vector< pair<int,int> > > lista(MAX);
priority_queue< pair<int,int>, vector< pair<int,int> >, cmp > Q;

void relajacion(const int act,const int ady,const int peso){
    if(distancia[act] + peso < distancia[ady]){
        distancia[ady]=distancia[act] + peso;
        previo[ady]=act;
        Q.push(make_pair(ady,distancia[ady]));
    }
}

void init(){
    for(int i=1;i<n+1;i++){
        visitado[i]=false;
        distancia[i]=INF;
        previo[i]=i;
    }
}

void dijkstra(){
    int act,ady,peso;
    Q.push(make_pair(o,0));
    distancia[o]=0;

    while(!Q.empty()){
        act = Q.top().first;
        Q.pop();

        if(visitado[act]) continue;
        visitado[act]=true;

        for(int i=0;i<lista[act].size();i++){
            ady=lista[act][i].first;
            peso=lista[act][i].second;
            if(!visitado[ady]){
                relajacion(act,ady,peso);
            }
        }
    }
}

void escribir(const int a){
    if(previo[a] != a)
        escribir(previo[a]);
    cout << a << ' ';
}

int main(){
    ifstream fin("in.txt");
    fin >> n >> o >> d;

    int a,b,c;
    init();

    while(fin >> a >> b >> c){
        lista[a].push_back(make_pair(b,c));
    }

    dijkstra();

    escribir(d);
}
