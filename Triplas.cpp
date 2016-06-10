#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct tripla{
    int one,two,three;
    tripla(int x1,int x2,int x3) : one(x1),two(x2),three(x3) {}
};

void sumadetripla(const vector<float> a){
    vector<tripla> Q;
    int tam = a.size(),maxim = 0,aux;
    int x=tam-1,c=tam-2,v=0;
    ofstream fout("out.txt");
    for(int i = 0;i<tam/3;i++){
        tripla nuevo(x,c,v);
        Q.push_back(nuevo);

        aux=a[x]+a[c]+a[v];
        if(aux > maxim) maxim = aux;

        x-=2;c-=2;v++;
    }
    cout << maxim << endl;
    vector<tripla>::iterator it = Q.begin();
    for(;it<Q.end();it++){
        cout << a[ (*it).one ] << ' ' << a[ (*it).two ] << ' ' << a[ (*it).three ] << endl;
    }
}

int main(){
    vector<float> lista;
    float a;
    ifstream fin("in.txt");
    fin >> a;
    while(a!=0){
        lista.push_back(a);
        fin >> a;
    }
    sort(lista.begin(),lista.end());
    sumadetripla(lista);
}
