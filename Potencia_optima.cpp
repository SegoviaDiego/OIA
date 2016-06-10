#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

void encontrarm(int& a,const int potencia){
    int aux=0;
    for(int i=2;i<potencia;i++){
            if(potencia%i == 0 && potencia/i > aux){
                aux = i;
            }
    }
    a = aux;
}

void encontrard(int& a,const int potencia){
    for(int i=potencia-1;i>0;i--){
            if(potencia%i == 0){
                a = i;
                return;
            }
    }
}

void calcular(const int m,const int d,const int p,const bool esprimo){
    int x,y,z;
    if(esprimo){
        x = 2;
        y = 1;
        z = 1;
        while(x!=p){
            cout << x << ' ' << y << ' ' << z << endl;
            for(int i = 1;i<=x;i++){
                if(x+i <= p){
                    z=i;
                }
            }
            y=x;
            x=y+z;
        }
        cout << x << ' ' << y << ' ' << z << endl;
    } else {
        x = m;
        y = m-1;
        z = 1;
        while(x!=d){
            cout << x << ' ' << y << ' ' << z << endl;
            for(int i = 1;i<=x;i++){
                if(x+i <= d){
                    z=i;
                }
            }
            y=x;
            x=y+z;
        }
        cout << x << ' ' << y << ' ' << z << endl;

        while(x!=p){
            y=x;
            x=y+d;
            cout << x << ' ' << y << ' ' << d << endl;
        }
    }

}

void isprime(const int a,bool& b){
    for(int i = 2;i<a;i++){
        if(a%i==0){
            b = false;
            return;
        }
    }
}

int main(){
    int potencia,divisor,multiplo;
    bool esprimo=true;
    ifstream fin("in.txt");
    fin >> potencia;
    encontrard(divisor,potencia);
    encontrarm(multiplo,potencia);
    isprime(potencia,esprimo);
    calcular(multiplo,divisor,potencia,esprimo);
}
