#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void leer(vector<int>& numero,string& linea){
    istringstream S(linea);
    int i; char a;
    while(S >> a){
        i = int(a) - int('0');
        numero.insert(numero.begin(),i);
    }
}

void escribir(vector<int> numero){
    ofstream fout("out.txt");
    vector<int>::iterator it = numero.end()-1;
    for(;it>(numero.begin()-1);it--){
        fout << *it;
    }
    fout << endl;
}

int maxsize(vector<int> a,vector<int> b){
    if(a.size() > b.size()){
        return a.size();
    } else {
        return b.size();
    }
}

void suma(vector<int> a,vector<int> b,vector<int>& r){
    int a_tam = a.size()-1,b_tam = b.size()-1,suma=0,cifras = maxsize(a,b),cifra_a,cifra_b,res,me_llevo=0;
    for(int i = 0;i<cifras;i++){
        if(a_tam<i) cifra_a = 0; else cifra_a = a[i];
        if(b_tam<i) cifra_b = 0; else cifra_b = b[i];
        suma = (cifra_a+cifra_b+me_llevo);
        res = suma % 10;
        me_llevo = suma / 10;
        r.push_back(res);
    }
    if(me_llevo>0){
        r.push_back(me_llevo);
    }
}

void multiplica1(vector<int> a, int numero, vector<int>& r){
    int multiplicacion,res,me_llevo=0;
    vector<int>::iterator it = a.begin();
    for(;it<a.end();it++){
        multiplicacion = (*it) * numero + me_llevo;
        res = multiplicacion % 10;
        me_llevo = multiplicacion / 10;
        r.push_back(res);
    }
    if(me_llevo>0){
        r.push_back(me_llevo);
    }
}

void multiplica10(vector<int>& a, int veces){
    vector<int>::iterator it = a.begin();
    for(int i = 0;i<veces;i++){
        a.insert(it,0);
    }
}

void copiar(vector<int>& a,vector<int>& b){
    vector<int>::iterator it = a.begin();
    b.clear();
    for(;it<a.end();it++){
        b.push_back(*it);
    }
}

void multiplica(vector<int> a,vector<int> b,vector<int>& r){
    vector<int> multiplicacion,res;
    int b_tam=b.size();
    for(int i=0;i<b_tam;i++){
        multiplica1(a,b[i],multiplicacion);
        multiplica10(multiplicacion,i);
        suma(multiplicacion,res,r);
        copiar(r,res);
        r.clear();
        multiplicacion.clear();
    }
    copiar(res,r);
}

int main(){
    vector<int> numero1,numero2,resultado;
    string linea;
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    getline(fin,linea);
    leer(numero1,linea);
    getline(fin,linea);
    leer(numero2,linea);

    multiplica(numero1,numero2,resultado);

    escribir(resultado);
}
