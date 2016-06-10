#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct sts{
    int x,y,pasos,direccion;
    sts(int x1,int x2,int x3,int x4) : x(x1),y(x2),pasos(x3),direccion(x4) {}
};

int main(){
    int s,in,entrada1,entrada2,salida1,salida2;
    queue<sts> Q;
    ifstream fin("in.txt");
    fin >> s;s++;
    int matriz[s][s]; bool visitado[s][s];
    for(int i = 1;i<s;i++){
        for(int j = 1;j<s;j++){
            fin >> in;
            visitado[i][j] = false;
            matriz[i][j] = in;
        }
    }
    fin >> entrada1 >> entrada2 >> salida1 >> salida2;

    sts nuevo(entrada1,entrada2,1,0);
    Q.push(nuevo);
    int x[4] = {-1,-1,1,1};
    int y[4] = {-1,1,1,-1};

    ofstream fout("out.txt");

    while(!Q.empty()){
        sts actual = Q.front();
        Q.pop();
        if(actual.x == salida1 && actual.y == salida2 ){
            fout << "SI" << endl << actual.pasos;
            return 0;
        }
        visitado[actual.x][actual.y] = true;
        for(int i = 0;i<4;i++){
            int nx = actual.x + x[i];
            int ny = actual.y + y[i];
            if( nx >= 1 && nx < s && ny >= 1 && ny < s && matriz[nx][ny] != 1 && !visitado[nx][ny]){
                    if( actual.direccion == 0 || actual.direccion == i ){
                        sts nuevo(nx,ny,actual.pasos,i);
                        Q.push(nuevo);
                    } else {
                        sts nuevo(nx,ny,actual.pasos+1,i);
                        Q.push(nuevo);
                    }
            }
        }

    }
    fout << "NO";
}
