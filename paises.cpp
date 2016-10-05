#include <bits/stdc++.h>
using namespace std;

vector< pair<string, vector<string> > > lista;
vector< pair<string,string> > listaingresados;

int Find(const string a){
    for(int i=0;i<lista.size();i++){
        if(lista[i].first == a)
            return i;
    }
    return -1;
}

bool Find2(const string a,const string b){
    for(int i=0;i<listaingresados.size();i++){
        if(listaingresados[i].first == a && listaingresados[i].second == b ||
           listaingresados[i].first == b && listaingresados[i].second == a){
            return true;
           }
    }
    return false;
}

bool Find3(const string a,const int x){
    for(int i=0;i<lista[x].second.size();i++){
        if(lista[x].second[i] == a)
            return true;
    }
    return false;
}

bool metodo(const pair<string, vector<string> > a,const pair<string, vector<string> > b){
    return a.first < b.first;
}

int main(){
    ifstream fin("in.txt");
    int n;
    vector<string> x;
    string input1,input2;
    fin >> n;

    while(fin >> input1 >> input2){
        n=Find(input1);
        if(n==-1){
            lista.push_back(make_pair(input1, x));
            lista[lista.size()-1].second.push_back(input2);
        } else {
            lista[n].second.push_back(input2);
        }

        n=Find(input2);
        if(n==-1){
            lista.push_back(make_pair(input2, x));
            lista[lista.size()-1].second.push_back(input1);
        } else {
            lista[n].second.push_back(input1);
        }
    }

    sort(lista.begin(),lista.end(),metodo);

    for(int i=0;i<lista.size();i++){
        cout << lista[i].first << ' ' << lista[i].second.size() << endl;
        listaingresados.push_back(make_pair(lista[i].first,lista[i].first));
        sort(lista[i].second.begin(),lista[i].second.end());
    }

    for(int i=0;i<lista.size();i++){
        for(int j=0;j<lista[i].second.size();j++){
            n=Find(lista[i].second[j]);
            for(int x=0;x<lista[n].second.size();x++){
                if(!Find2(lista[i].first,lista[n].second[x]) && !Find3(lista[n].second[x], i)){
                    cout << lista[i].first << ' ' << lista[n].second[x] << endl;
                    listaingresados.push_back(make_pair(lista[i].first,lista[n].second[x]));
                }
            }
        }
    }
}
