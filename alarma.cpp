#include <bits/stdc++.h>
using namespace std;


vector<string> lista;
vector< pair<string,int> > inputs;

int Find(const string a,const int b){
    int res=0;
    for(int i=0;i<b;i++){
        if( inputs[i].first == a.substr(0,inputs[i].first.size() ) ){
            res++;
        }
    }
    if(res==0)
        lista.push_back(a);
    return res;
}

bool metodo1(const pair<string,int> a, const pair<string,int> b){
    if(a.first.size() == b.first.size())
        return a.first < b.first;
    return a.first.size() < b.first.size();
}

int main(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int n;
    string input;
    fin >> n;

    while(fin >> input){
        inputs.push_back(make_pair(input,0));
    }

    sort(inputs.begin(),inputs.end(),metodo1);

    for(int i=0;i<inputs.size();i++){
        n=Find(inputs[i].first,i);
        if(n!=0)
            inputs[i].second = n;
    }

    for(int i=0;i<lista.size();i++){
        fout << 0 << ' ' << lista[i] << endl;
        for(int j=0;j<inputs.size();j++){
            if(inputs[j].second!=0){
                if(lista[i] == inputs[j].first.substr(0,lista[i].size())){
                    fout << inputs[j].second << ' ' << inputs[j].first << endl;
                }
            }
        }
    }

}
