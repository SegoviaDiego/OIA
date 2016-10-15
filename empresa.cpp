#include <bits/stdc++.h>
using namespace std;

int total=0;
vector< pair<string, vector<string> > > lista;
vector<string> res;

void rellenar(vector< pair< string, bool> >& visitado){
    for(int i=0;i<lista.size();i++){
        visitado.push_back(make_pair(lista[i].first,false));
    }
}

int Find(const string a){
    for(int i=0;i<lista.size();i++){
        if(a==lista[i].first) return i;
    }
    return -1;
}

int Find2(const string a, const vector< pair< string, bool> > visitado){
    for(int i=0;i<visitado.size();i++){
        if(a==visitado[i].first) return i;
    }
    return -1;
}

void bfs(const int a){
    queue< pair<string, int> > Q;
    Q.push(make_pair(lista[a].first,1));
    vector< pair< string, bool> > visitado;
    rellenar(visitado);

    while(!Q.empty()){
        pair<string,int> actual= Q.front();
        Q.pop();

        if(actual.second==5){
            total++;
            res.push_back(lista[a].first);
            return;
        }

        if(visitado[Find2(actual.first,visitado)].second) continue;
        visitado[Find2(actual.first,visitado)].second=true;

        for(int i=0;i<lista[Find(actual.first)].second.size();i++){
            if(!visitado[Find2(lista[Find(actual.first)].second[i],visitado)].second){
                Q.push(make_pair(lista[Find(actual.first)].second[i],actual.second+1));
            }
        }
    }

}

int main(){
    ifstream fin("in.txt");

    int n;
    string input1,input2;

    fin >> n;

    while(fin >> input1 >> input2){
        if(Find(input1)==-1){
            vector<string> v;
            v.push_back(input2);
            lista.push_back(make_pair(input1,v));
        } else {
            lista[Find(input1)].second.push_back(input2);
        }

        if(Find(input2)==-1){
            vector<string> v2;
            v2.push_back(input1);
            lista.push_back(make_pair(input2,v2));
        } else {
            lista[Find(input2)].second.push_back(input1);
        }
    }

    for(int i=0;i<lista.size();i++){
        bfs(i);
    }

    cout << total << endl;

    sort(res.begin(),res.end());

    for(int i=0;i<res.size();i++){
        cout << res[i] << endl;
    }
}
