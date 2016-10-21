#include <bits/stdc++.h>
using namespace std;

#define MAX 2000

int t,ph,pv;
char matriz[MAX][MAX];

void init(){
    for(int i=1;i<t+1;i++){
        for(int j=1;j<t+1;j++){
            matriz[i][j]='.';
        }
    }
}

void escribir(){
    for(int i=1;i<t+1;i++){
        for(int j=1;j<t+1;j++){
            cout << matriz[i][j];
        }
        cout << endl;
    }
}

char color(const char a,const int x,const int y){
    if(matriz[x][y]=='.'){
        return a;
    } else if(a=='R'){
        if(matriz[x][y]=='Z'){
            return 'P';
        } else if(matriz[x][y]=='A'){
            return 'N';
        } else {
            return matriz[x][y];
        }
    } else if(a=='Z'){
        if(matriz[x][y]=='R'){
            return 'P';
        } else if(matriz[x][y]=='A'){
            return 'V';
        } else {
            return matriz[x][y];
        }
    } else if(a=='A'){
        if(matriz[x][y]=='Z'){
            return 'V';
        } else if(matriz[x][y]=='R'){
            return 'N';
        } else {
            return matriz[x][y];
        }
    }
}

void pintar(const int a,const char b,const int c,const int d,const int dir){
    if(dir==1){
        for(int i=c;i<=d;i++){
            matriz[a][i]=color(b,a,i);
        }
    } else {
        for(int i=c;i<=d;i++){
            matriz[i][a]=color(b,i,a);
        }
    }
}

int main(){
    ifstream fin("in.txt");
    fin >> t >> ph >> pv;

    int a,c,d;
    char b;
    init();

    for(int i=0;i<ph;i++){
        fin >> a >> b >> c >> d;
        pintar(a,b,c,d,1);
    }

    for(int i=0;i<pv;i++){
        fin >> a >> b >> c >> d;
        pintar(a,b,c,d,2);
    }

    escribir();

}
