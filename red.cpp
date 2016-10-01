#include <bits/stdc++.h>
using namespace std;

#define MAX 1000010

int union_find[MAX];

int Find(const int a){
    if(a == union_find[a])
        return a;
    return union_find[a] = Find(union_find[a]);
}

void Union(const int a, const int b){
    union_find[Find(a)]=Find(b);
}

int main(){
    ifstream fin("in.txt");

    int p1, p2;
    char issue;

    for(int i=0;i<MAX;i++){
        union_find[i]=i;
    }

    while(fin >> issue >> p1 >> p2){
        if(issue=='P'){
            if(Find(p1) == Find(p2) ){
                cout << 'S' << endl;
            } else {
                cout << 'N' << endl;
            }
        } else {
            Union(Find(p1), Find(p2));
        }
    }
}
