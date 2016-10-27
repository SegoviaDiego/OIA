//TIEMPO: 37:22
#include <bits/stdc++.h>
using namespace std;

#define MAX 5000
vector<int> num;

int main(){
    ifstream fin("in.txt");
    ifstream finn("in.txt");
    string linea;
    int n,m,l,largo=0;
    fin >> n >> m;
    getline(finn,linea);
    getline(finn,linea);
    char a;

    while(m>=10){
        num.push_back(m%10);
        m/=10;
        largo++;
    }
    largo++;
    num.push_back(m);

    if(largo<n){
        for(int i=largo;i<n;i++){
            num.push_back(0);
        }
    }
    reverse(num.begin(),num.end());

    l=0;

    for(int i=0;i<linea.size();i++){
        a=linea[i];
        if(l==num.size()){
            l=0;
        }
        if(a!=' '){
            if(int(a)+num[l] > int('Z')){
                cout << char( int('A')+((num[l]-1)-abs(int(a)-int('Z'))) );
            } else {
                cout << char( int(a)+num[l] );
            }
            l++;
        }
    }
}
