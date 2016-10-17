#include <bits/stdc++.h>
using namespace std;

int total=0;
vector< pair< pair<int,int>,int > > esquinas;
queue< pair<pair<int,int>,int > > Q;

void rellenar(vector<bool> &visitado){
    for(int i=0;i<esquinas.size();i++){
        visitado.push_back(false);
    }
}

int dist(const int a, const int b,const int c){
    if(c==1) return abs(esquinas[a].first.first-esquinas[b].first.first);
    return abs(esquinas[a].first.second-esquinas[b].first.second);
}

void calcular(const int i){
    vector<bool> visitado;
    rellenar(visitado);
                            // Posición   direccion peso
    Q.push(make_pair(make_pair(esquinas[i].second,1),1));

    while(!Q.empty()){
        pair<pair<int,int>,int> actual = Q.front();
        Q.pop();

        if(visitado[actual.first.first]) continue;
        visitado[actual.first.first]=true;

        for(int i=0;i<esquinas.size();i++){
            if(i!=actual.first.first){
                if(actual.first.second == 1){
                    if(esquinas[actual.first.first].first.first < esquinas[i].first.first && esquinas[actual.first.first].first.second == esquinas[i].first.second) Q.push(make_pair(make_pair(esquinas[i].second,1),actual.second+dist(esquinas[i].second,actual.first.first,1)));
                    if(esquinas[actual.first.first].first.first == esquinas[i].first.first && esquinas[actual.first.first].first.second < esquinas[i].first.second) Q.push(make_pair(make_pair(esquinas[i].second,2),actual.second+dist(esquinas[i].second,actual.first.first,2)));
                } else if(actual.first.second == 2){
                    if(esquinas[actual.first.first].first.first == esquinas[i].first.first && esquinas[actual.first.first].first.second < esquinas[i].first.second) Q.push(make_pair(make_pair(esquinas[i].second,2),actual.second+dist(esquinas[i].second,actual.first.first,2)));
                    if(esquinas[actual.first.first].first.first > esquinas[i].first.first && esquinas[actual.first.first].first.second == esquinas[i].first.second) Q.push(make_pair(make_pair(esquinas[i].second,3),actual.second+dist(esquinas[i].second,actual.first.first,1)));
                } else if(actual.first.second == 3){
                    if(esquinas[actual.first.first].first.first > esquinas[i].first.first && esquinas[actual.first.first].first.second == esquinas[i].first.second) Q.push(make_pair(make_pair(esquinas[i].second,3),actual.second+dist(esquinas[i].second,actual.first.first,1)));
                    if(esquinas[actual.first.first].first.first == esquinas[i].first.first && esquinas[actual.first.first].first.second > esquinas[i].first.second) Q.push(make_pair(make_pair(esquinas[i].second,4),actual.second+dist(esquinas[i].second,actual.first.first,2)));
                } else{
                    total=max(total,actual.second);
                }
            }
        }

    }
}

int main(){
    ifstream fin("in.txt");

    int n,m,e,x,y,index=0;

    fin >> n >> m >> e;

    while(fin >> x >> y){
        esquinas.push_back(make_pair(make_pair(x,y),index));
        index++;
    }

    for(int i=0;i<esquinas.size();i++){
        calcular(i);
    }

    cout << "Archivo con " << e << " esquinas da largo " << total+1 << "." << endl;
}
