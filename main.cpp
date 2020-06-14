#include <iostream>
using namespace std;

int num = 4;
int numOfMinterm = 0;
int numOfDoncare = 0;

string size1PI[16][3];
string size2PI[32][3];
string size4PI[16][3];
string size8PI[8][3];
string size16PI[1][3];

int num1pi = 0;
int num2pi = 0;
int num4pi = 0;
int num8pi = 0;
int num16pi = 0;

int hd(string a, string b){
    int diff = 0;
    for(int i = 0; i<4; i++)
        if(a[i] != b[i]) diff++;
    if(diff == 1)
        return 1;
    else return 0;
}

string newBin(string a, string b){
    string newbin = "0000";
    for(int i = 0; i<4; i++){
        if(a[i]!=b[i])
            newbin[i] = '-';
        else newbin[i] = a[i];
    }
    return newbin;
}

int check(string inputList[][3], string outputList[][3], int inputNum, int outputNum){
    for(int i = 0; i<inputNum; i++){
        for(int j = 0; j<inputNum; j++){
            if(hd(inputList[i][1], inputList[j][1])){
                string tmp = newBin(inputList[i][1], inputList[j][1]);
                int same = 0;
                for(int i = 0; i<=inputNum; i++){
                    if(tmp.compare(outputList[i][1]) == 0)
                        same = 1;
                }
                if(!same){
                    outputList[outputNum][0] = inputList[i][0] + " " + inputList[j][0];
                    outputList[outputNum++][1] = tmp;    
                }
                inputList[i][2] = "1";
                inputList[j][2] = "1";
            }
        }
    }
    for(int i = 0; i<inputNum; i++){
        if(inputList[i][2] != "1")
            cout << inputList[i][0] << "\n";
    }

    if(outputNum > 1)
        return 1, outputNum;
    else{
        return 0, outputNum;
    }
}

string makeBin(int n){
    string Bin = "0000";
    for(int i = 3; i>=0; i--){
        if(n%2) Bin[i] = '1';
        else Bin[i] = '0';
        n/=2;
    }
    return Bin;
}

int main(){    
    int tmp, pi;
    cout << "----Input number of minterms----\n";
    cin >> numOfMinterm;
    cout << "----Input number of doncares----\n";
    cin >> numOfDoncare;
    num1pi = numOfDoncare + numOfMinterm;
    cout << "-------Please input data--------\n";
    for(int i = 0; i<num1pi; i++){
        cin >> tmp;
        size1PI[i][0] = to_string(tmp);
        size1PI[i][1] = makeBin(tmp);
    }
    cout << "----------Print PI List---------\n";
    pi, num2pi = check(size1PI, size2PI, num1pi, num2pi);
    if(pi)
        pi, num4pi = check(size2PI, size4PI, num2pi, num4pi);
    if(pi)
        pi, num8pi = check(size4PI, size8PI, num4pi, num8pi);
    if(pi)
        pi, num16pi = check(size8PI, size16PI, num8pi, num16pi);
}
