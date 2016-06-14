#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct nombres{
    string nombre;
    int repeticiones;
    nombres(string x1,int x2) : nombre(x1),repeticiones(x2) {}
};

bool existe(const vector<nombres> a,const string b,int& c){
    vector<nombres>::const_iterator it = a.begin();
    for(int i = 0;it<a.end();it++,i++){
        if( (*it).nombre == b ){
            c = i;
            return true;
        }
    }
    return false;
}

bool metodo(const nombres a,const nombres b){
    return a.repeticiones > b.repeticiones;
}

void escribir(const vector<nombres> a,const int b){
    vector<nombres>::const_iterator it = a.begin();
    ofstream fout("out.txt");
    for(int i = 0;i<b;i++,it++){
        fout << (*it).nombre << ' ' << (*it).repeticiones << endl;
    }
}

int main(){
    vector<nombres> lista;
    int x,pos=0;
    string in;
    ifstream fin("in.txt");
    fin >> x >> x;
    fin >> in;
    while(!fin.eof()){
        if(existe(lista,in,pos)){
            lista[pos].repeticiones+=1;
        } else {
            nombres nuevo(in,1);
            lista.push_back(nuevo);
        }
        fin >> in;
    }
    sort(lista.begin(),lista.end(),metodo);
    escribir(lista,x);
}
