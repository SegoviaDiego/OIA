/*

Nombre: Viaje de negocios
Tiempo: 27:47
Problema: Nivel 3 Problema 1 valija Certamen Nacional OIA 2013

*/
#include <bits/stdc++.h>
using namespace std;

int s,n;
vector< pair<int,int> > lista;

bool metodo(const pair<int,int> a,const pair<int,int> b){
    if(a.first==b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    ifstream fin("in.txt");
    fin >> s >> n;
    int a,b,altura=0,largo=0,ancho=0,cantidad=0;
    while(fin >> a >> b){
        lista.push_back(make_pair(a,b));
    }

    sort(lista.begin(),lista.end(),metodo);

    for(int i=0;i<lista.size();i++){
        if( ((lista[i].first+lista[i].second)+(largo+1)) <= s){
            altura=max(altura,lista[i].first);
            ancho=max(ancho,lista[i].second);
            largo++;
            cantidad++;
        }
    }

    cout << cantidad << endl;
}
