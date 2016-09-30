#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct aristas{
    int origen,destino,peso;

    bool operator<(const aristas &A){
        return peso < A.peso;
    }
};

int Find(vector<int> &a,int b){
    if(b == a[b])
        return b;
    else return a[b] = Find(a,a[b]);
}

void Union(vector<int> &a,const int b,const int c){
    a[Find(a,b)]=Find(a,c);
}

int main(){
    int n,m,input,input2,total=0;
    vector<int> ciudades;
    vector<aristas> conexiones;
    aristas nuevo;

    cin >> n;

    ciudades.push_back(0);

    for(int i=0;i<n;i++){
        ciudades.push_back(i+1);
        nuevo.origen=i+1;
        for(int j=0;j<n;j++){
            cin >> input;
            if(j!=i){
                nuevo.destino=j+1;
                nuevo.peso=input;
                conexiones.push_back(nuevo);
            }
        }
    }

    cin >> m;

    for(int i=0;i<m;i++){
        cin >> input >> input2;
        Union(ciudades,input,input2);
    }

    sort(conexiones.begin(),conexiones.end());

    for(int i=0;i<conexiones.size();i++){
        if(Find(ciudades, conexiones[i].origen) != Find(ciudades, conexiones[i].destino)){
            Union(ciudades,conexiones[i].origen,conexiones[i].destino);
            total+=conexiones[i].peso;
        }
    }

    cout << total << endl;
}
