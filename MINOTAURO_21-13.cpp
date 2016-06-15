#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

struct camino{
    int nombre,conectacon,pasos;
    camino (int x1,int x2,int x3) : nombre(x1),conectacon(x2),pasos(x3) {}
};

void nuevocamino(vector<camino>& a,string linea,int mismo){
    istringstream S(linea);
    int c,elemento=1;

    camino nuevo(mismo+1,0,0);
    a.push_back(nuevo);

    while(S >> c){
        if(c==0){
            a[mismo].nombre = elemento;
        } else {
            if(a[mismo].conectacon == 0){
                a[mismo].conectacon = elemento;
                a[mismo].pasos = c;
            } else {
                if(c < a[mismo].pasos){
                    a[mismo].conectacon = elemento;
                    a[mismo].pasos = c;
                }
            }
        }
        elemento++;
    }
}

void escribir(vector<camino> a){
    vector<camino>::iterator it = a.begin();
    ofstream fout("out.txt");
    fout << a.size()-1 << endl;
    for(;it<a.end()-1;it++){
        fout << (*it).nombre << ' ' << (*it).conectacon << ' ' << (*it).pasos << endl;
    }
}

int main(){
    vector<camino> lista;
    int caminos,mismo=0;
    string linea;
    ifstream fin("in.txt");
    fin >> caminos;
    getline(fin,linea);
    while(getline(fin,linea)){
        nuevocamino(lista,linea,mismo);
        mismo++;
    }
    escribir(lista);
}
