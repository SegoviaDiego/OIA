#include <bits/stdc++.h>
using namespace std;

#define INF 51
#define MAX 500005

struct aristas{
    int destino, peso, calle;
    bool direccion;

    aristas(int x1, int x2, int x3, bool x4) : destino(x1), peso(x2), calle(x3), direccion(x4) {}
};

struct cmp{
    bool operator()(const aristas &a, const aristas &b){
        return a.peso > b.peso;
    }
};

int previo[MAX];
int distancia[MAX];
int calle[MAX];
bool cambiodemano[MAX];
bool visitado[MAX];
priority_queue< aristas, vector<aristas>, cmp> Q;

void relajacion(int actual, int adyacente, int peso,int nc, bool cdm){
    if(distancia[actual] + peso < distancia[adyacente]){
        distancia[adyacente]=distancia[actual]+peso;
        previo[adyacente]=actual;
        calle[previo[adyacente]]=nc;
        cambiodemano[nc]=cdm;
        aristas n(adyacente,distancia[adyacente],nc,cdm);
        Q.push(n);
    }
}

void escribir(const int i){
    if(previo[i] != -1){
        if(cambiodemano[calle[previo[i]]]){
            cout << calle[previo[i]] << ' ';
        }
        escribir(previo[i]);
    }
}

int main (){
    ifstream fin("in.txt");

    int nodos,origen, destino, o, d, p, v=0;
    fin >> nodos >> origen >> destino >> d;

    vector< vector<aristas> > lista(nodos+1);

    for(int i=1;i<nodos+1;i++){
        visitado[i]=false;
        previo[i]=-1;
        distancia[i]=INF;
    }

    while(fin >> o >> d >> p){
        v++;
        aristas nuevo(d, p, v, false);
        aristas nuevo2(o, p, v, true);
        lista[o].push_back(nuevo);
        lista[d].push_back(nuevo2);
    }

    int ady,peso;
    aristas nuevo(origen, 0, 0, false);
    distancia[origen]=0;
    Q.push(nuevo);
    while(!Q.empty()){
        aristas actual=Q.top();
        Q.pop();

        if(visitado[actual.destino]) continue;
        visitado[actual.destino]=true;

        for(int i=0;i<lista[actual.destino].size();i++){
            if( !visitado[ lista[actual.destino][i].destino ]){
                relajacion(actual.destino, lista[actual.destino][i].destino, lista[actual.destino][i].peso,
                           lista[actual.destino][i].calle, lista[actual.destino][i].direccion);
            }
        }
    }

    cout << distancia[destino] << endl;
    escribir(destino);
}
