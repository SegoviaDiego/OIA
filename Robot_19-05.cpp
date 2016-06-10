#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

struct Robot{
    int x,y;
    char sentido;
};

void avanzar(Robot& R,int pasos,int n,int m){
    switch(R.sentido){
    case 'N':
        for(;R.y<m;pasos--){
            if(pasos==0){
                return;
            }
            R.y++;
        }
        break;
    case 'S':
        for(;R.y>1;pasos--){
            if(pasos==0){
                return;
            }
            R.y--;
        }
        break;
    case 'E':
        for(;R.x<n;pasos--){
            if(pasos==0){
                return;
            }
            R.x++;
        }
        break;
    case 'O':
        for(;R.x>1;pasos--){
            if(pasos==0){
                return;
            }
            R.y--;
        }
        break;
    }
}

void rotar(Robot& R,int pasos){
    switch(pasos){
    case 1:
    case 5:
    case 9:
        switch(R.sentido){
        case 'N':
            R.sentido = 'E';
            break;
        case 'S':
            R.sentido = 'O';
            break;
        case 'E':
            R.sentido = 'S';
            break;
        case 'O':
            R.sentido = 'N';
            break;
        }
        break;
    case 2:
    case 6:
        switch(R.sentido){
        case 'N':
            R.sentido = 'S';
            break;
        case 'S':
            R.sentido = 'N';
            break;
        case 'E':
            R.sentido = 'O';
            break;
        case 'O':
            R.sentido = 'E';
            break;
        }
        break;
    case 3:
    case 7:
        switch(R.sentido){
        case 'N':
            R.sentido = 'O';
            break;
        case 'S':
            R.sentido = 'E';
            break;
        case 'E':
            R.sentido = 'N';
            break;
        case 'O':
            R.sentido = 'S';
            break;
        }
        break;
    }
}


int main(){
    Robot robo; int i;char a; string linea;
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int n,m;
    fin >> robo.x >> robo.y >> robo.sentido >> n >> m;

    getline(fin,linea);
    getline(fin,linea);
    istringstream S(linea);
    while(S >> a >> i){
        switch(a){
        case 'A':
            avanzar(robo,i,n,m);
            break;
        case 'R':
            rotar(robo,i);
            break;
        }
    }
    fout << robo.x << ' ' << robo.y;
}
