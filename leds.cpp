#include <bits/stdc++.h>
using namespace std;

int actual=0;

struct cmp{
    bool operator()(const int &a, const int &b){
        if(abs(a-actual) == abs(b-actual))
            return a > b;
        return abs(a-actual) > abs(b-actual);
    }
};

priority_queue <int > Conectores;
priority_queue <int , vector<int> , cmp> Leds;

int main(){
    ifstream fin("in.txt");

    int n,L;
    char input;
    vector< pair<int, int> > lista;

    fin >> n;
    n=0;

    while(fin >> input){
        n++;
        if(input == 'C'){
            Conectores.push(n);
        } else {
            Leds.push(n);
        }
    }

    while(!Conectores.empty()){
        actual=Conectores.top();
        Conectores.pop();

        L=Leds.top();
        Leds.pop();

        lista.push_back(make_pair(actual,L));
    }

    cout << lista.size() << endl;

    for(int i=0;i<lista.size();i++){
        cout << lista[i].first << ' ' << lista[i].second << endl;
    }

}
