#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void terminar(bool entra,const int i,const int j,const int f,const int l,const int dx,const int dy,const int dir){
    ofstream fout("out.txt");
    char direc;

    if(dir == 1){
        direc = 'S';
    } else {
        direc = 'E';
    }

    if(entra){
        fout << "SI" << endl << i+1 << ' ' << j+1 << endl << direc;
    } else {
        fout << "NO" << endl;
    }
}

int main(){
    int dx,dy,f,l,a,b,actx,acty;
    bool entra;
    ifstream fin("in.txt");
    fin >> dx >> dy >> f >> l;
    int matriz[dx][dy];
    fin >> a;
    fin >> a >> b;

    for(int i =0;i<dx;i++){
        for(int j=0;j<dy;j++){
            matriz[i][j] = 0;
        }
    }

    while(!fin.eof()){
        matriz[a-1][b-1] = 1;
        fin >> a >> b;
    }

    for(int i = 0;i<dx;i++){
        for(int j = 0;j<dy;j++){
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i = 0;i<dx;i++){
        for(int j = 0;j<dy;j++){
                if(true){
                        entra = true;
                        cout << "1 ---------" << endl;
                        for(int cx = 0;cx<f;cx++){
                            for(int cy = 0;cy<l;cy++){
                                    actx = i+cx;
                                    acty = j+cy;
                                    if(actx+1>dx || acty+1>dy) entra = false;
                                    cout << i+cx << '-' << j+cy << ' ';
                                    if(matriz[actx][acty] == 1) {
                                        entra = false;
                                    }
                            }
                            cout << endl;
                        }
                        if(entra) {
                            terminar(entra,i,j,f,l,dx,dy,1);
                            return 0;
                        }
                }
                if(true){
                        entra = true;
                        cout << "2 ---------" << endl;
                        for(int cx = 0;cx<l;cx++){
                            for(int cy = 0;cy<f;cy++){
                                    actx = i+cx;
                                    acty = j+cy;
                                    if(actx+1>dx || acty+1>dy) entra = false;
                                    cout << i+cx << '-' << j+cy << ' ';
                                    if(matriz[actx][acty] == 1) {
                                        entra = false;
                                    }
                            }
                            cout << endl;
                        }
                        if(entra) {
                            terminar(entra,i,j,f,l,dx,dy,2);
                            return 0;
                        }
                }
        }
    }
    terminar(false,0,0,0,0,0,0,0);
}
