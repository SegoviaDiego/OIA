#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct pos{
    int empieza,termina,nivel;
    pos(int x1,int x2,int x3) : empieza(x1),termina(x2),nivel(x3) {}
};

void leer(vector<char>& a,vector<pos>& b,string linea){
    int x=0,c=0;
    for(int i = 0;i<linea.length();i++){
        if(linea[i] == '('){
            x+=1;
            pos nuevo(c,0,0);
            b.push_back(nuevo);
        } else if(linea[i] == ')'){
            if(b.size()>1){
                b[b.size()-(b.size()-x)].termina = c;
                b[b.size()-(b.size()-x)].nivel = x;
                x-=1;
            } else {
                b[0].termina = c;
                b[0].nivel = x;
                x-=1;
            }
        } else {
            c++;
            a.push_back(linea[i]);
        }
    }
}

void girar(vector<char>&a,const vector<pos> b){
    vector<pos>::const_iterator it = b.begin();
    for(;it<b.end();it++){
        reverse(a.begin()+(*it).empieza,a.begin()+(*it).termina);
    }
}

void escribir(const vector<char> a){
    vector<char>::const_iterator it = a.begin();
    ofstream fout("out.txt");
    for(;it<a.end();it++){
        fout << (*it);
    }
}

bool metodo(pos a,pos b){
    return a.nivel > b.nivel;
}

int main(){
    vector<char> mensaje;
    vector<pos> reverselist;
    string linea;
    ifstream fin("in.txt");
    getline(fin,linea);
    leer(mensaje,reverselist,linea);
    sort(reverselist.begin(),reverselist.end(),metodo);
    girar(mensaje,reverselist);
    escribir(mensaje);
}
