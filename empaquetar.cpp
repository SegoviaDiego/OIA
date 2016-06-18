#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct hoja{
    int r;
    hoja (int x1) : r(x1) {}
};

bool metodo(hoja a,hoja b){
    return a.r < b.r;
}

void calcular(const vector<hoja> a,const int S){
    vector<hoja>::const_iterator it = a.begin();
    int aux=0,paquetes=0;
    for(;it<a.end();it++){
        cout << aux << ' ' << (*it).r << endl;
        if( (*it).r >= S ){
            paquetes++;
        } else if( aux+(*it).r == S ){
            aux=0;
            paquetes++;
        } else if( aux+(*it).r > S ){
            aux=0;
            paquetes++;
        } else {
            aux+=(*it).r;
        }
    }
    if(aux>0) paquetes++;
    ofstream fout("out.txt");
    fout << paquetes;
}

int main(){
    vector<hoja> lista;
    ifstream fin("in.txt");
    int z,x,c,S,r;
    fin >> S >> z;
    fin >> z >> x >> c;
    while(!fin.eof()){
        r = z+x+c;
        hoja nuevo(r);
        lista.push_back(nuevo);
        fin >> z >> x >> c;
    }
    sort(lista.begin(),lista.end(),metodo);
    calcular(lista,S);
}
