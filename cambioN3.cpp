/*

Nombre: Cambio de mano de una calle
Tiempo: 38:16
Problema: Nivel 3 Problema 3 invertir Certamen Nacional OIA 2013

*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 5000
#define INF 1000000

struct cmp{
    bool operator()(const pair<int,int> a, const pair<int,int> b){
        return a.second > b.second;
    }
};

int n,o,d,c;
int previo[MAX];
int distancia[MAX];
bool visitado[MAX];
vector< vector< pair<int,int> > > lista(MAX);
vector< pair< pair<int,int>,int > > calles;
vector< pair<int,int> > res;
priority_queue< pair<int,int>, vector< pair<int,int> >, cmp> Q;

bool metodo( const pair<int,int> a, const pair<int,int> b ){
    return a.second < b.second;
}

void init(){
    for(int i=0;i<n+1;i++){
        visitado[i]=false;
        distancia[i]=INF;
        previo[i]=i;
    }
}

void relajacion(const int act,const int ady,const int peso){
    if(distancia[act] + peso < distancia[ady]){
        distancia[ady]=distancia[act] + peso;
        previo[ady]=act;
        Q.push(make_pair(ady,distancia[ady]));
    }
}

void dijkstra(){
    init();
    int act,ady,peso;
    Q.push(make_pair(o,0));
    distancia[o]=0;

    while(!Q.empty()){
        act=Q.top().first;
        Q.pop();

        if(visitado[act])continue;
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

void dijkstra2(const vector< vector< pair<int,int> > > lista){
    init();
    int act,ady,peso;
    Q.push(make_pair(o,0));
    distancia[o]=0;

    while(!Q.empty()){
        act=Q.top().first;
        Q.pop();

        if(visitado[act])continue;
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

int Find(const int a,const int b,const vector< vector< pair<int,int> > > lista2){
    for(int i=0;i<lista2[a].size();i++){
        if(lista2[a][i].first == b) return i;
    }
}

void cambiar(const int a,const int b,vector< vector< pair<int,int> > >& lista2){
    int pos=Find(a,b,lista2);
    lista2[b].push_back(make_pair(a,lista2[a][pos].second));
    lista2[a].erase(lista2[a].begin()+pos);
}

int main(){
    ifstream fin("in.txt");
    fin >> n >> o >> d >> c;
    int a,b,x=0;
    while(fin >> a >> b >> c){
        x++;
        lista[a].push_back(make_pair(b,c));
        calles.push_back(make_pair(make_pair(a,b),x));
    }

    dijkstra();
    int fd=distancia[d];
    cout << fd << endl;

    int one,two;

    for(int i=0;i<calles.size();i++){
        one=calles[i].first.first;
        two=calles[i].first.second;
        vector< vector< pair<int,int> > > lista2 = lista;
        cambiar(one,two,lista2);
        dijkstra2(lista2);
        res.push_back(make_pair(calles[i].second,distancia[d]));
    }

    sort(res.begin(),res.end(),metodo);

    if(res[0].second < fd){
        cout << res[0].second << endl << res[0].first << endl;
    } else {
        cout << "NO ES POSIBLE MEJORAR" << endl;
    }
}
