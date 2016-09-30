#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct aristas{
    int origen,destino,peso;

    bool operator<(const aristas &E){
        return peso < E.peso;
    }
};

int Find(vector<int> &a,const int b){
    if(b == a[b])
        return b;
    else return a[b] = Find(a,a[b]);
}

void Union(vector<int> &a,const int b,const int c){
    a[Find(a,b)]=Find(a,c);
}

int main(){
    int n,m,input1,input2,total=0;
    vector<int> esquinas;
    vector<aristas> conexiones;
    aristas nuevo;
    nuevo.peso=1;

    esquinas.push_back(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        esquinas.push_back(i+1);
        nuevo.origen=i+1;
        for(int j=0;j<n;j++){
            if(j!=i){
                nuevo.destino=j+1;
                conexiones.push_back(nuevo);
            }
        }
    }

    for(int i=0;i<m;i++){
        cin >> input1 >> input2;
        Union(esquinas,input1,input2);
    }

    for(int i=0;i<conexiones.size();i++){
        if(Find(esquinas,conexiones[i].origen) != Find(esquinas,conexiones[i].destino)){
            Union(esquinas,conexiones[i].origen,conexiones[i].destino);
            total+=1;
        }
    }

    cout << total;

}
