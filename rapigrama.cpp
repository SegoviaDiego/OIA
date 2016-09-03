#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    vector<string> lista;
    vector<string> v;
    string linea;
    int n,d;
    fin >> d >> n;
    for(int i=0;i<d;i++){
        fin >> linea;
        lista.push_back(linea);
    }
    for(int i=0;i<d;i++){
        linea="";
        for(int j=0;j<d;j++){
            linea+=lista[j][i];
        }
        lista.push_back(linea);
    }
    for(int i=0;i<(d+d);i++){
        linea = lista[i];
        reverse(linea.begin(),linea.end());
        lista.push_back(linea);
    }
    for(int i=0;i<n;i++){
        fin >> linea;
        for(int j=0;j<lista.size();j++){
            if(lista[j].find(linea)<lista[j].size()-1){
                if(j<d){
                    fout << i+1 << ' ' << 'E' << endl;
                } else if(j<d*2){
                    fout << i+1 << ' ' << 'S' << endl;
                } else if(j<d*3){
                    fout << i+1 << ' ' << 'O' << endl;
                } else {
                    fout << i+1 << ' ' << 'N' << endl;
                }
                break;
            }
        }
    }
}
