#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct campo{
    int x,altura,nivel;
    campo(int x1,int x3,int x5) : x(x1),altura(x3),nivel(x5) {}
};

int main(){
    ifstream fin("in.txt");
    vector<int> caminofinal;
    vector<int> camino;
    queue<campo> Q;
    int tam,a;
    fin >> tam;
    int matriz[tam][300];
    bool visitado[tam][300];
    for(int i=0;i<tam;i++){
        for(int j=0;j<300;j++){
            matriz[i][j]=-1;
            visitado[i][j]=false;
        }
    }
    while(fin >> a){
        camino.push_back(a);
    }
    //bfs
    campo nuevo(0,1,0);
    visitado[0][1]=true;
    matriz[0][1]=camino[0]-1;
    Q.push(nuevo);
    int dy[2]={1,-1};
    while(!Q.empty()){
        campo actual = Q.front();
        Q.pop();
        for(int i=0;i<2;i++){
            int newaltura = actual.altura+dy[i];
            if(newaltura >= 0 && newaltura <=299){
                int distotal = matriz[actual.x][actual.altura] + abs(camino[actual.nivel+1]-newaltura);
                if(visitado[actual.x+1][newaltura]==true){
                    if(matriz[actual.x+1][newaltura] > distotal){
                        matriz[actual.x+1][newaltura] = distotal;
                        if(actual.nivel+1 == tam-1){
                            caminofinal[caminofinal.size()-1]=distotal;
                        } else {
                            campo n(actual.x+1,newaltura,actual.nivel+1);
                            Q.push(n);
                        }
                    }
                } else {
                    visitado[actual.x+1][newaltura]=true;
                    matriz[actual.x+1][newaltura] = distotal;
                    if(actual.nivel+1 == tam-1){
                            caminofinal.push_back(distotal);
                        } else {
                            campo n(actual.x+1,newaltura,actual.nivel+1);
                            Q.push(n);
                        }
                }
            }
        }
    }
    sort(caminofinal.begin(),caminofinal.end());
    cout << caminofinal[0];
}
