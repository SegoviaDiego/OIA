#include <bits/stdc++.h>
using namespace std;

#define MAX 300100

int total,n,a,c,d;
char b;
int visitado[MAX];
vector<pair<int,string> > res;
vector< pair< char,vector<int> > > lista(MAX);
stack< pair<int,char> > Q;

bool metodo(const pair<int,string> a, const pair<int,string> b){
    return a.first < b.first;
}

void init(){
    for(int i=1;i<n+1;i++){
        visitado[i]=false;
    }
}

void dfs(){
    pair<int,int> act;int ady;char c;
    //Repetición con inicial = A y tipo A B

    init();

    if(lista[1].first=='C'){
        c='A';
        total=1;
    } else {
        c=lista[1].first;
        total=0;
    }
    Q.push(make_pair(1,c));
    visitado[1]=true;

    while(!Q.empty()){
        act=Q.top();
        Q.pop();

        visitado[act.first]=true;

        for(int i=0;i<lista[act.first].second.size();i++){
            ady=lista[act.first].second[i];
            if(!visitado[ady]){
                if(lista[ady].first == act.second || lista[ady].first == 'C'){
                    if(act.second == 'A'){
                        Q.push(make_pair(ady,'B'));
                        total++;
                    } else {
                        Q.push(make_pair(ady,'A'));
                        total++;
                    }
                } else {
                    Q.push(make_pair(ady,lista[ady].first));
                }
            }
        }
    }
    res.push_back(make_pair(total," A B"));

    //Repetición con inicial = A y tipo A C

    init();

    if(lista[1].first=='B'){
        c='A';
        total=1;
    } else {
        c=lista[1].first;
        total=0;
    }
    Q.push(make_pair(1,c));
    visitado[1]=true;

    while(!Q.empty()){
        act=Q.top();
        Q.pop();

        visitado[act.first]=true;

        for(int i=0;i<lista[act.first].second.size();i++){
            ady=lista[act.first].second[i];
            if(!visitado[ady]){
                if(lista[ady].first == act.second || lista[ady].first == 'B'){
                    if(act.second == 'A'){
                        Q.push(make_pair(ady,'C'));
                        total++;
                    } else {
                        Q.push(make_pair(ady,'A'));
                        total++;
                    }
                } else {
                    Q.push(make_pair(ady,lista[ady].first));
                }
            }
        }
    }
    res.push_back(make_pair(total," A C"));

    //Repetición con inicial = B y tipo B A

    init();

    if(lista[1].first=='C'){
        c='B';
        total=1;
    } else {
        c=lista[1].first;
        total=0;
    }
    Q.push(make_pair(1,c));
    visitado[1]=true;

    while(!Q.empty()){
        act=Q.top();
        Q.pop();

        visitado[act.first]=true;

        for(int i=0;i<lista[act.first].second.size();i++){
            ady=lista[act.first].second[i];
            if(!visitado[ady]){
                if(lista[ady].first == act.second || lista[ady].first == 'C'){
                    if(act.second == 'A'){
                        Q.push(make_pair(ady,'B'));
                        total++;
                    } else {
                        Q.push(make_pair(ady,'A'));
                        total++;
                    }
                } else {
                    Q.push(make_pair(ady,lista[ady].first));
                }
            }
        }
    }
    res.push_back(make_pair(total," B A"));

    //Repetición con inicial = B y tipo B C

    init();

    if(lista[1].first=='A'){
        c='B';
        total=1;
    } else {
        c=lista[1].first;
        total=0;
    }
    Q.push(make_pair(1,c));
    visitado[1]=true;

    while(!Q.empty()){
        act=Q.top();
        Q.pop();

        visitado[act.first]=true;

        for(int i=0;i<lista[act.first].second.size();i++){
            ady=lista[act.first].second[i];
            if(!visitado[ady]){
                if(lista[ady].first == act.second || lista[ady].first == 'A'){
                    if(act.second == 'C'){
                        Q.push(make_pair(ady,'B'));
                        total++;
                    } else {
                        Q.push(make_pair(ady,'C'));
                        total++;
                    }
                } else {
                    Q.push(make_pair(ady,lista[ady].first));
                }
            }
        }
    }
    res.push_back(make_pair(total," B C"));

     //Repetición con inicial = C y tipo C A

    init();

    if(lista[1].first=='B'){
        c='C';
        total=1;
    } else {
        c=lista[1].first;
        total=0;
    }
    Q.push(make_pair(1,c));
    visitado[1]=true;

    while(!Q.empty()){
        act=Q.top();
        Q.pop();

        visitado[act.first]=true;

        for(int i=0;i<lista[act.first].second.size();i++){
            ady=lista[act.first].second[i];
            if(!visitado[ady]){
                if(lista[ady].first == act.second || lista[ady].first == 'B'){
                    if(act.second == 'C'){
                        Q.push(make_pair(ady,'A'));
                        total++;
                    } else {
                        Q.push(make_pair(ady,'C'));
                        total++;
                    }
                } else {
                    Q.push(make_pair(ady,lista[ady].first));
                }
            }
        }
    }
    res.push_back(make_pair(total," C A"));

    //Repetición con inicial = C y tipo C B

    init();

    if(lista[1].first=='A'){
        c='C';
        total=1;
    } else {
        c=lista[1].first;
        total=0;
    }
    Q.push(make_pair(1,c));
    visitado[1]=true;

    while(!Q.empty()){
        act=Q.top();
        Q.pop();

        visitado[act.first]=true;

        for(int i=0;i<lista[act.first].second.size();i++){
            ady=lista[act.first].second[i];
            if(!visitado[ady]){
                if(lista[ady].first == act.second || lista[ady].first == 'A'){
                    if(act.second == 'C'){
                        Q.push(make_pair(ady,'B'));
                        total++;
                    } else {
                        Q.push(make_pair(ady,'C'));
                        total++;
                    }
                } else {
                    Q.push(make_pair(ady,lista[ady].first));
                }
            }
        }
    }
    res.push_back(make_pair(total," C B"));
}

int main(){
    ifstream fin("in.txt");

    fin >> n;

    for(int i=0;i<n;i++){
        fin >> a >> b >> c;
        lista[a].first=b;
        for(int i=0;i<c;i++){
            fin >> d;
            lista[a].second.push_back(d);
        }
    }

    dfs();

    sort(res.begin(),res.end(),metodo);

    cout << res[0].first << res[0].second << endl;
}
