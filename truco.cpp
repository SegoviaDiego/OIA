#include <bits/stdc++.h>
using namespace std;

int n,m,k,input;
vector<int> lista;
vector<int> res;

int Find(const int a){
    for(int i=0;i<lista.size();i++){
        if(lista[i]==a) return i;
    }
}

int devolver(int a){
    int aux=k,pos=Find(a)+1;
    while(aux>0){
        if(pos+aux > n){
            if(pos==n){
                aux-=1;
                pos=1;
            } else {
                aux-=abs(pos-n);
                pos=1;
            }
        } else{
            pos+=aux;
            aux=0;
        }
    }
    return pos;
}

int main(){
    ifstream fin("in.txt");

    fin >> n;

    for(int i=0;i<n;i++){
        fin >> input;
        lista.push_back(input);
    }

    fin >> m;

    for(int i=0;i<m;i++){
        fin >> input;
        res.push_back(input);
    }

    fin >> k;

    reverse(lista.begin(),lista.end());

    for(int i=0;i<m;i++){
        cout << res[i] << ' ' << devolver(res[i]) << endl;
    }
}
