#include <bits/stdc++.h>
using namespace std;

long long int dist(const long long int a,const long long int b){
    return sqrt((a*a)+(b*b));
}

int main(){
    ifstream fin("in.txt");

    long long int n,input,velocidad,actual,altura;
    vector<long long int> lista;

    fin >> n;

    for(int i=0;i<n;i++){
        fin >> input;
        lista.push_back(input);
    }

    fin >> actual;

    if(lista[0]<lista[1]){
        cout << actual << ' ' << lista[0]+actual;
    } else {
        velocidad=lista[0]-actual;
        actual=lista[0]-lista[1];
        altura=lista[0];
        for(int i=1;i<lista.size();i++){

            if(i!=1){
                if(velocidad>0){
                    if(lista[i]<lista[i-1]){
                        velocidad-=1;
                        altura=lista[i];
                        actual+=abs(lista[i]-lista[i-1]);
                    } else {
                        if(dist(lista[i],lista[i-1])>velocidad){
                            actual+=ceil(sqrt((velocidad*velocidad)/2));
                            altura+=ceil(sqrt((velocidad*velocidad)/2));
                            velocidad=0;
                        } else {
                            altura=lista[i];
                            actual+=abs(lista[i]-lista[i-1]);
                        }
                    }
                } else {
                    break;
                }
            } else {
                if(velocidad>0){
                    if(lista[i]<lista[i-1]){
                        velocidad-=1;
                        altura=lista[i];
                    } else {
                        if(dist(lista[i],lista[i-1])>velocidad){
                            actual+=ceil(sqrt((velocidad*velocidad)/2));
                            altura+=ceil(sqrt((velocidad*velocidad)/2));
                            velocidad=0;
                        } else {
                            altura=lista[i];
                        }
                    }
                } else {
                    break;
                }
            }
        }
        cout << actual << ' ' << altura;
    }
}
