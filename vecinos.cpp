#include <bits/stdc++.h>
using namespace std;

#define MAX 10005
#define INF -1
#define INF2 1<<30

struct cmp{
    bool operator()(const pair<int,int> a,const pair<int,int> b){
        return a.second < b.second;
    }
};

int distancia1[MAX];
bool visitado1[MAX];
int distancia2[MAX];
bool visitado2[MAX];

int edge1[MAX];
int edge2[MAX];

int previo1[MAX];
int previo2[MAX];
priority_queue < pair<int,int>, vector< pair<int,int> >, cmp> Q;

void relajacion1(const int actual, const int adyacente, const int peso){
    if(distancia1[actual] + peso > distancia1[adyacente]){
        distancia1[adyacente]=distancia1[actual] + peso;
        previo1[adyacente]=actual;
        edge1[adyacente]=peso;
        Q.push(make_pair(adyacente,distancia1[adyacente]));
    }
}

void relajacion2(const int actual, const int adyacente, const int peso){
    if(distancia2[actual] + peso > distancia2[adyacente]){
        distancia2[adyacente]=distancia2[actual] + peso;
        previo2[adyacente]=actual;
        edge2[adyacente]=peso;
        Q.push(make_pair(adyacente,distancia2[adyacente]));
    }
}

int menorpath1(const int a, int b){
    if(previo1[a]!=a)
        return menorpath1(previo1[a],min(b,edge1[a]));
    return b;
}

int menorpath2(const int a, int b){
    if(previo2[a]!=a)
        return menorpath2(previo2[a],min(b,edge2[a]));
    return b;
}

void escribir1(const int a){
    if(previo1[a]!=a)
        escribir1(previo1[a]);
    cout << a << ' ';
}

void escribir2(const int a){
    if(previo2[a]!=a)
        escribir2(previo2[a]);
    cout << a << ' ';
}

int main(){
    ifstream fin("in.txt");

    int vecinos,lazos,x,y,in1,in2,in3,actual,x1=0,y1=0;

    fin >> vecinos >> lazos >> x >> y;

    vector< vector< pair<int,int> > > lista(vecinos+1);

    for(int i=1;i<vecinos+1;i++){
        distancia1[i]=INF;
        distancia2[i]=INF;
        visitado1[i]=false;
        visitado2[i]=false;
        previo1[i]=i;
        previo2[i]=i;
        edge1[i]=i;
        edge2[i]=i;
    }

    while(fin >> in1 >> in2 >> in3){
        lista[in1].push_back(make_pair(in2,in3));
        lista[in2].push_back(make_pair(in1,in3));
    }

    //Inicio dijkstra para el PRIMER vecino

    Q.push(make_pair(x,0));
    distancia1[x]=0;
    while(!Q.empty()){
        actual = Q.top().first;
        Q.pop();

        if(visitado1[actual]) continue;
        visitado1[actual]=true;

        for(int i=0;i<lista[actual].size();i++){
            if(!visitado1[ lista[actual][i].first ]){
                relajacion1(actual,lista[actual][i].first,lista[actual][i].second);
            }
        }
    }

    //Inicio dijkstra para el SEGUNDO vecino

    Q.push(make_pair(y,0));
    distancia2[y]=0;
    while(!Q.empty()){
        actual = Q.top().first;
        Q.pop();

        if(visitado2[actual]) continue;
        visitado2[actual]=true;

        for(int i=0;i<lista[actual].size();i++){
            if(!visitado2[ lista[actual][i].first ]){
                relajacion2(actual,lista[actual][i].first,lista[actual][i].second);
            }
        }
    }

    //Comprobaciones

    for(int i=1;i<vecinos+1;i++){
        if(i!=x && i!=y && distancia1[i] != distancia2[i]){
            if(menorpath1(i,INF2) > menorpath2(i,INF2)){
                x1++;
            } else {
                y1++;
            }
        }
    }

    cout << x1 << ' ' << y1 << endl;
}
