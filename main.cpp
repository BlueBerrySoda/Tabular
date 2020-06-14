#include <iostream>
#include <bitset>
using namespace std;

int num = 4;
int numOfMinterm = 6;
int numOfDoncare = 2;
int sumOfNum = numOfDoncare+numOfMinterm;

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

void check8(){
    for(int i = 0; i<num8pi; i++){
        for(int j = 0; j<num8pi; j++){
            if(hd(size8PI[i][1], size8PI[j][1])){
                string tmp = newBin(size8PI[i][1], size8PI[j][1]);
                int same = false;
                for(int i = 0; i<=num8pi; i++){
                    if(tmp.compare(size16PI[i][1]) == 0)
                        same = true;
                }
                if(!same){
                    size8PI[num16pi][0] = size8PI[i][0] + " " + size8PI[j][0];
                    size8PI[num16pi++][1] = tmp;    
                }
                size8PI[i][2] = "1";
                size8PI[j][2] = "1";
            }
        }
    }
    for(int i = 0; i<num8pi; i++){
        if(size8PI[i][2] != "1")
            cout << size8PI[i][0] << "\n";
    }

    if(num16pi <= 1)
        cout << size8PI[0][0] << "\n";
}

void check4(){
    for(int i = 0; i<num4pi; i++){
        for(int j = 0; j<num4pi; j++){
            if(hd(size4PI[i][1], size4PI[j][1])){
                string tmp = newBin(size4PI[i][1], size4PI[j][1]);
                int same = false;
                for(int i = 0; i<=num4pi; i++){
                    if(tmp.compare(size8PI[i][1]) == 0)
                        same = true;
                }
                if(!same){
                    size4PI[num8pi][0] = size4PI[i][0] + " " + size4PI[j][0];
                    size4PI[num8pi++][1] = tmp;    
                }
                size4PI[i][2] = "1";
                size4PI[j][2] = "1";
            }
        }
    }
    for(int i = 0; i<num4pi; i++){
        if(size4PI[i][2] != "1")
            cout << size4PI[i][0] << "\n";
    }

    if(num8pi > 1)
        check8();
    else
        cout << size8PI[0][0] << "\n";
}

void check2(){
    for(int i = 0; i<num2pi; i++){
        for(int j = 0; j<num2pi; j++){
            if(hd(size2PI[i][1], size2PI[j][1])){
                string tmp = newBin(size2PI[i][1], size2PI[j][1]);
                int same = false;
                for(int i = 0; i<=num2pi; i++){
                    if(tmp.compare(size4PI[i][1]) == 0)
                        same = true;
                }
                if(!same){
                    size4PI[num4pi][0] = size2PI[i][0] + " " + size2PI[j][0];
                    size4PI[num4pi++][1] = tmp;    
                }
                size2PI[i][2] = "1";
                size2PI[j][2] = "1";
            }
        }
    }
    for(int i = 0; i<num2pi; i++){
        if(size2PI[i][2] != "1")
            cout << size2PI[i][0] << "\n";
    }

    if(num4pi > 1)
        check4();
    else
        cout << size4PI[0][0] << "\n";
}

void check1(){
    for(int i = 0; i<sumOfNum; i++){
        for(int j = 0; j<sumOfNum; j++){
            if(hd(size1PI[i][1], size1PI[j][1])){
                string tmp = newBin(size1PI[i][1], size1PI[j][1]);
                int same = false;
                for(int i = 0; i<=sumOfNum; i++){
                    if(tmp.compare(size2PI[i][1]) == 0)
                        same = true;
                }
                if(!same){
                    size2PI[num2pi][0] = size1PI[i][0] + " " + size1PI[j][0];
                    size2PI[num2pi++][1] = tmp;
                }
                size1PI[i][2] = "1";
                size1PI[j][2] = "1";
            }
        }
    }
    for(int i = 0; i<sumOfNum; i++){
        if(size1PI[i][2] != "1")
            cout << size1PI[i][0] << "\n";
    }

    if(num2pi > 1)
        check2();
    else
        cout << size2PI[0][0] << "\n";
}

int numOfOne(string bin){
    int one = 0;
    for(int i = 0; i<4; i++){
        if(bin[i] == '1')
            one++;
    }
    return one;
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
    int tmp;
    for(int i = 0; i<sumOfNum; i++){
        cin >> tmp;
        size1PI[i][0] = to_string(tmp);
        size1PI[i][1] = makeBin(tmp);
    }
    check1();
}
