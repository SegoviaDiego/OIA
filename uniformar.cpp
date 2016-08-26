#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <sstream>
using namespace std;

struct campo{
    int valor,x,y;
    campo(int x1,int x2,int x3) : valor(x1), x(x2), y(x3) {}
};

int main(){
    int tam,x=0,y=0;
    char tile;
    string linea;
    ifstream fin("in.txt");
    fin >> tam;
    bool visitado[tam][tam],terminado=false;
    int matriz[tam][tam];
    getline(fin,linea);
    while(getline(fin,linea)){
        istringstream S(linea);
        while(S >> tile){
            visitado[x][y]=false;
            matriz[x][y]=(int(tile)-int('0'));
            y++;
        }
        y=0;
        x++;
    }
    int posx[4]={0,0,1,-1};
    int posy[4]={1,-1,0,0};
    int reps=0;
    queue<campo> Q;
    while(!terminado){
        campo nuevo1(matriz[0][0],0,0);
        Q.push(nuevo1);
        if(matriz[0][0] == 1){
            matriz[0][0] = 0;
        } else {
            matriz[0][0] = 1;
        }
        while(!Q.empty()){
            campo actual = Q.front();
            Q.pop();
            visitado[actual.x][actual.y] = true;
            for(int i=0;i<4;i++){
                int actx = actual.x + posx[i];
                int acty = actual.y + posy[i];
                if(actx >= 0 && actx < tam && acty >=0 && acty <tam){
                    if(visitado[actx][acty] == false){
                        if(matriz[actx][acty]==actual.valor){
                            if(actual.valor==0){
                                matriz[actx][acty]=1;
                            } else {
                                matriz[actx][acty]=0;
                            }
                            campo nuevo(actual.valor,actx,acty);
                            Q.push(nuevo);
                        }
                    }
                }
            }
        }

        terminado=true;
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                visitado[i][j]=false;
                if(matriz[i][j] != matriz[0][0]){
                    terminado=false;
                }
            }
        }
        reps++;
    }
    ofstream fout("out.txt");
    fout << reps;
}
