#include <iostream>
using namespace std;

int main(){
    cout << "Hello\n";
    int num = 4;
    int numOfMinterm = 6;
    int numOfDoncare = 2;
    int sumOfNum = numOfDoncare+numOfMinterm;
    int minterms[sumOfNum];
    int table[num][num];
    int tmp;
    for(int i = 0; i<sumOfNum; i++){
        cin >> tmp;
        minterms[i] = tmp; 
    }
    
}
