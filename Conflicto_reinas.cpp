#include <bits/stdc++.h>
using namespace std;

int X,Y;

struct reinas{
    int nombre,x,y,tipo;
};

bool metodo(const reinas a, const reinas b){
    return (abs(a.x-X)+abs(a.y-Y)) < (abs(b.x-X)+abs(b.y-Y));
}

bool metodo2(const reinas a,const reinas b){
    return a.nombre < b.nombre;
}

int main(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int n,m;
    vector<reinas> lista;

    fin >> n >> m;

    for(int i=0;i<m;i++){
        reinas nuevo;
        fin >> nuevo.x >> nuevo.y;
        nuevo.nombre=i+1;
        lista.push_back(nuevo);
    }

    bool visitado[8];

    for(int i=0;i<m;i++){
        X=lista[i].x;
        Y=lista[i].y;

        for(int j=0;j<8;j++){
                visitado[j]=false;
        }

        vector<reinas> conflictos;
        vector<reinas> res;

        for(int j=0;j<m;j++){
            if(i!=j){
                if(lista[i].x == lista[j].x || lista[i].y == lista[j].y){
                    if(lista[i].x == lista[j].x && lista[i].y < lista[j].y)lista[j].tipo=0;
                    if(lista[i].x == lista[j].x && lista[i].y > lista[j].y)lista[j].tipo=1;
                    if(lista[i].x < lista[j].x && lista[i].y == lista[j].y)lista[j].tipo=2;
                    if(lista[i].x > lista[j].x && lista[i].y == lista[j].y)lista[j].tipo=3;
                    conflictos.push_back(lista[j]);
                } else if( abs(lista[i].x-lista[j].x) == abs(lista[i].y-lista[j].y) ){
                    if(lista[i].x < lista[j].x && lista[i].y < lista[j].y) lista[j].tipo=4;
                    if(lista[i].x > lista[j].x && lista[i].y > lista[j].y) lista[j].tipo=5;
                    if(lista[i].x < lista[j].x && lista[i].y > lista[j].y) lista[j].tipo=6;
                    if(lista[i].x > lista[j].x && lista[i].y < lista[j].y) lista[j].tipo=7;
                    conflictos.push_back(lista[j]);
                }
            }
        }

        sort(conflictos.begin(),conflictos.end(),metodo);

        for(int j=0;j<conflictos.size();j++){
            if(visitado[conflictos[j].tipo]==false){
                visitado[conflictos[j].tipo]=true;
                res.push_back(conflictos[j]);
            }
        }

        sort(res.begin(),res.end(),metodo2);

        fout << res.size() << ' ';
        for(int j=0;j<res.size();j++){
            fout << res[j].nombre << ' ';
        }
        fout << endl;
    }

}
