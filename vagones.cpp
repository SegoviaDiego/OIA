#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct animal{
    int agresividad;
    animal (int x) : agresividad(x) {}
};

bool metodo(const animal a,const animal b){
    return a.agresividad < b.agresividad;
}

void calcular(const vector<animal> a,const int maxagr){
    vector<animal>::const_iterator it = a.begin();
    int minagr=a[a.size()-1].agresividad,aux=0,vagones=0;
    for(;it<a.end();it++){
        if( (*it).agresividad >= maxagr ){
            if( (*it).agresividad < minagr ) minagr=(*it).agresividad;
            vagones++;
        } else if( aux+(*it).agresividad == maxagr ){
            if( maxagr < minagr ) minagr=maxagr;
            vagones++;
            aux=0;
        } else if( aux+(*it).agresividad > maxagr){
            if( aux < minagr ) minagr=aux;
            aux=(*it).agresividad;
            vagones++;
        } else {
            aux+=(*it).agresividad;
        }
    }
    if(aux>0){
        if( aux < minagr ) minagr=aux;
        vagones++;
    }
    ofstream fout("out.txt");
    fout << vagones << ' ' << minagr;
}

int main(){
    vector<animal> lista;
    ifstream fin("in.txt");
    int a,maxagr,x;
    string b;
    fin >> maxagr >> maxagr;
    fin >> b >> a >> x;
    while(!fin.eof()){
        animal nuevo(a);
        lista.push_back(nuevo);
        fin >> b >> a >> x;
    }
    sort(lista.begin(),lista.end(),metodo);
    calcular(lista,maxagr);
}
