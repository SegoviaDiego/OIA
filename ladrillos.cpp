#include <bits/stdc++.h>
using namespace std;

struct unidad{
    long long int valor;
    bool isnumber;
};

bool Find(const vector<unidad> v){
    for(int i=0;i<v.size();i++){
        if(!v[i].isnumber) return true;
    }
    return false;
}

int main(){
    ifstream fin("in.txt");
    ifstream fin2("in.txt");

    int n,a,b,c;
    bool ingresado=false;
    char input;
    unidad nuevo;
    nuevo.valor=0;
    nuevo.isnumber=false;
    string linea;

    vector<unidad> lista;

    fin2 >> n;

    getline(fin,linea);
    getline(fin,linea);

    for(int i=0;i<linea.size();i++){
        input=linea[i];

        if(input != ' ' && ingresado==false){
            ingresado=true;
            if(input=='*'){
                fin2 >> input;
                nuevo.isnumber=false;
            } else {
                nuevo.isnumber=true;
                fin2 >> nuevo.valor;
            }
            lista.push_back(nuevo);
        } else {
            ingresado=false;
        }
    }

    while(Find(lista)){
        for(int i=0;i<lista.size()-2;i++){
            if(lista[i].isnumber && lista[i+1].isnumber){
                lista[i+2].valor=lista[i].valor+lista[i+1].valor;
                lista[i+2].isnumber=true;
            } else if( lista[i].isnumber && lista[i+2].isnumber ){
                lista[i+1].isnumber=true;
                lista[i+1].valor=abs(lista[i].valor-lista[i+2].valor);
            }
        }

        for(int i=lista.size()-1;i>4;i--){
            if(lista[i].isnumber && lista[i-1].isnumber){
                lista[i-2].valor=lista[i].valor-lista[i-1].valor;
                lista[i-2].isnumber=true;
            } else if( lista[i].isnumber && lista[i-2].isnumber ){
                lista[i-1].isnumber=true;
                lista[i-1].valor=abs(lista[i].valor-lista[i-2].valor);
            }
        }
    }

    for(int i=0;i<lista.size();i++){
        cout << lista[i].valor << ' ';
    }
}
