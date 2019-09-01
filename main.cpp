#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    string linha;
    ifstream arquivo;
    arquivo.open(argv[1]);

    while(getline (arquivo,linha)){
        cout << linha << endl;
    };

    arquivo.close();
    return 0;
}