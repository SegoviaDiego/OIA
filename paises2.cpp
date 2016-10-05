#include <bits/stdc++.h>
using namespace std;

vector< pair<string, vector<string> > > lista;
vector< pair<string,string> > listain;
vector< pair<string,string> > res;

int Find(const string a){
    for(int i=0;i<lista.size();i++){
        if(lista[i].first == a)
            return i;
    }
    return -1;
}

bool FindX(const string a,const string b){
    for(int i=0;i<listain.size();i++){
        if( (listain[i].first == a) && (listain[i].second == b) ||
            (listain[i].first == b) && (listain[i].second == a)){
               return true;
           }
    }
    return false;
}

bool metodo(const pair<string, vector<string> > a,const pair<string, vector<string> > b){
    return a.first < b.first;
}

bool metodo2(const pair<string,string> a,const pair<string,string> b){
    if( a.first == b.first )
        return a.second < b.second;
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
        listain.push_back(make_pair(input1,input2));
    }

    sort(lista.begin(),lista.end(),metodo);

    for(int i=0;i<lista.size();i++){
        cout << lista[i].first << ' ' << lista[i].second.size() << endl;
        listain.push_back(make_pair(lista[i].first,lista[i].first));
        sort(lista[i].second.begin(),lista[i].second.end());
    }

    for(int i=0;i<lista.size();i++){
        for(int j=0;j<lista[i].second.size();j++){
            n=Find(lista[i].second[j]);
            for(int x=0;x<lista[n].second.size();x++){
                if(!FindX(lista[i].first,lista[n].second[x])){
                    listain.push_back(make_pair(lista[i].first,lista[n].second[x]));
                    res.push_back(make_pair(lista[i].first,lista[n].second[x]));
                }
            }
        }
    }

    sort(res.begin(),res.end(),metodo2);

    if(res.size() == 0){
        cout << "No hay paises translimitrofes" << endl;
    } else {
        for(int i=0;i<res.size();i++){
            cout << res[i].first << ' ' << res[i].second << endl;
        }
    }
}
