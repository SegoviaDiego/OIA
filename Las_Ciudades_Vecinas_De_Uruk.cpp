#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct aristas{
    int origen,destino,peso;

    bool operator<(const aristas &A){
        return peso < A.peso;
    }
};

int Find(vector<int> &a,const int b){
    if(b==a[b])
        return b;
    else return a[b] = Find(a,a[b]);
}

void Union(vector<int> &a,const int b,const int c){
    a[Find(a,b)]=Find(a,c);
}

int FindNombre(const vector<string> a,const string nombre){
    for(int i=0;i<a.size();i++){
        if(a[i] == nombre)
            return i;
    }
    return -1;
}

int main(){
    int n,m,total=0;
    string n1,n2;
    vector<int> union_find;
    vector<string> ciudades;
    vector<aristas> conexiones;
    aristas arista;
    ciudades.push_back("-1");
    union_find.push_back(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        union_find.push_back(i+1);
    }

    for(int i=0;i<m;i++){
        cin >> n1 >> n2 >> arista.peso;
        arista.origen=FindNombre(ciudades,n1);
        arista.destino=FindNombre(ciudades,n2);

        if(arista.origen==-1){
            ciudades.push_back(n1);
            arista.origen=ciudades.size()-1;
        }
        if(arista.destino==-1){
            ciudades.push_back(n2);
            arista.destino=ciudades.size()-1;
        }
        conexiones.push_back(arista);
    }

    sort(conexiones.begin(),conexiones.end());

    for(int i=0;i<conexiones.size();i++){

        if(Find(union_find,conexiones[i].origen) != Find(union_find,conexiones[i].destino)){
            Union(union_find,conexiones[i].origen,conexiones[i].destino);
            total+=conexiones[i].peso;
        }
    }

    cout << total << endl;
}
