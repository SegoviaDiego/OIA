#include <bits/stdc++.h>
using namespace std;

struct categoria{
    int i,f;
};

struct corredor{
    int edad;
    char sexo;
};

int main(){
    ifstream fin("in.txt");

    int a,cf,cm,l,input,edad;
    char sexo;
    categoria cn;
    corredor corredorn;
    vector<categoria> categoriaf;
    vector<categoria> categoriam;
    vector<corredor> listacorredores;
    vector<int> listallegada;
    fin >> a >> cf >> cm >> l;

    for(int i=0;i<cf;i++){
        fin >> cn.i >> cn.f;
        categoriaf.push_back(cn);
    }

    for(int i=0;i<cm;i++){
        fin >> cn.i >> cn.f;
        categoriam.push_back(cn);
    }

    listacorredores.push_back(corredorn);
    for(int i=0;i<a;i++){
        fin >> corredorn.edad >> corredorn.sexo;
        listacorredores.push_back(corredorn);
    }

    for(int i=0;i<l;i++){
        fin >> input;
        listallegada.push_back(input);
    }

    for(int i=0;i<cf;i++){
        vector<int>ganadores;
        for(int j=0;j<l;j++){
            if(ganadores.size()==3) break;
            edad=listacorredores[listallegada[j]].edad;
            sexo=listacorredores[listallegada[j]].sexo;

            if((edad >= categoriaf[i].i && edad <= categoriaf[i].f) && sexo=='F'){
                ganadores.push_back(listallegada[j]);
            }
        }
        cout << i+1 << ' ';
        if(ganadores.size()==3){
            cout << ganadores[0] << ' ' << ganadores[1] << ' ' << ganadores[2] << endl;
        } else if(ganadores.size()==2){
            cout << ganadores[0] << ' ' << ganadores[1] << ' ' << 0 << endl;
        } else if(ganadores.size()==1){
            cout << ganadores[0] << ' ' << 0 << ' ' << 0 << endl;
        } else {
            cout << 0 << ' ' << 0 << ' ' << 0 << endl;
        }
    }

    for(int i=0;i<cm;i++){
        vector<int>ganadores;
        for(int j=0;j<l;j++){
            if(ganadores.size()==3) break;
            edad=listacorredores[listallegada[j]].edad;
            sexo=listacorredores[listallegada[j]].sexo;

            if((edad >= categoriam[i].i && edad <= categoriam[i].f) && sexo=='M'){
                ganadores.push_back(listallegada[j]);
            }
        }
        cout << i+1 << ' ';
        if(ganadores.size()==3){
            cout << ganadores[0] << ' ' << ganadores[1] << ' ' << ganadores[2] << endl;
        } else if(ganadores.size()==2){
            cout << ganadores[0] << ' ' << ganadores[1] << ' ' << 0 << endl;
        } else if(ganadores.size()==1){
            cout << ganadores[0] << ' ' << 0 << ' ' << 0 << endl;
        } else {
            cout << 0 << ' ' << 0 << ' ' << 0 << endl;
        }
    }
}
