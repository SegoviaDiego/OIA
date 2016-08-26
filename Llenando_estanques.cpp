#include <bits/stdc++.h>
using namespace std;

struct tanque{
    int nombre,ocupa,base,altura;
    tanque(int x1,int x2,int x3,int x4) : nombre(x1),ocupa(x2),base(x3),altura(x4) {}
};

int main(){
    fstream fin("in.txt");
    int n,s,p,pc,agua,indice;
    vector<tanque> v;
    fin >> n;

    for(int i=0;i<n-1;i++){
        fin >> s >> p >> pc;
        tanque nuevo(i+1,s*(p-pc),s,p);
        v.push_back(nuevo);
    }
    fin >> s >> p;

    tanque nuevo(v[v.size()].nombre+1,s*p,s,p);
    v.push_back(nuevo);

    fin >> agua;

    for(int i=0;i<n;i++){
        if(agua==0) break;

        if(agua > v[i].ocupa){
            agua-=v[i].ocupa;
            v[i].ocupa = v[i].ocupa/v[i].base;
        } else {
            indice=i+1;
            v[i].ocupa = agua/v[i].base;
            agua=0;
        }
    }

    if(agua==0){
        cout << indice << endl;
        for(int i=0;i<indice;i++){
            cout << v[i].nombre << ' ' << floor(v[i].ocupa) << endl;
        }
    } else {
        cout << "Hay desborde: " << agua << endl;
    }
}
