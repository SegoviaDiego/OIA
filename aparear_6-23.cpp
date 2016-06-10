#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void sumadepares(const vector<float> a){
    vector<float>::const_iterator it = a.begin();
    int tam = a.size(),i=0, j=tam-1;
    ofstream fout("out.txt");
    for(;i<tam/2;i++,j--){
            fout << a[i] << ' ' << a[j] << endl;
    }
}

int main(){
    vector<float> lista;
    float a;
    ifstream fin("in.txt");
    fin >> a;
    while(!fin.eof()){
        lista.push_back(a);
        fin >> a;
    }
    sort(lista.begin(),lista.end());
    sumadepares(lista);
}
