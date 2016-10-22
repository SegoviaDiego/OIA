#include <bits/stdc++.h>
using namespace std;

#define MAX 500

int c,n,a,b;
vector< pair<int,vector<int> > > listadeventas(MAX);
vector< vector<int> > lista(MAX);

bool Find(const int a){
    for(int i=0;i<lista.size();i++){
        if(lista[i].size()>=n)
            return true;
    }
    return false;
}

int calcular(const int a){
    int res=0,nuevo;
    for(int i=0;i<(lista[a].size()-n)+1;i++){
        nuevo=0;
        for(int j=0;j<n;j++){
            nuevo+=lista[a][i+j];
        }
        res=max(res,nuevo);
    }
    return res;
}

bool res(vector< pair<int,int> > &top){
    bool rest;
    for(int i=0;i<lista.size();i++){
        if(lista[i].size()>=n){
            top.push_back(make_pair(i+1,calcular(i)));
            rest=true;
        }
    }
    return rest;
}

bool metodo(const pair<int,int> a, const pair<int,int> b){
    return a.second > b.second;
}

int main(){
    ifstream fin("in.txt");
    fin >> c;

    for(int i=0;i<c;i++){
        fin >> a;
        for(int j=0;j<a;j++){
            fin >> b;
            lista[i].push_back(b);
        }
    }

    fin >> n;

    bool done=false;

    if(Find(n)){
        while(Find(n)){
            vector< pair<int,int> > top;
            if(res(top)){
                sort(top.begin(),top.end(),metodo);
                if(top.size() > 1){
                    sort(top.begin(),top.end(),metodo);
                    if(top[0].second != top[1].second){
                        cout << top[0].first << endl << n << ' ' << top[0].second << endl;
                        done=true;
                        break;
                    }
                } else {
                    cout << top[0].first << endl << n << ' ' << top[0].second << endl;
                    done=true;
                    break;
                }
            }

            n++;
        }

        if(!done)
            cout << "No se puede desempatar" << endl;

    } else {
        cout << "No hay ganadoras" << endl;
    }
}
