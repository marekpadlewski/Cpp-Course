#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


bool primeNumber(int64_t num){

    bool con = true;

    for (int64_t i = 2 ; i*i <= num ; i++) {
        if (num % i == 0){
            con = false;
            break;
        }
    }

    return con;
}

vector<int64_t> primeFactors(int64_t num){

    vector <int64_t> V;

    if (num == 0 || num == 1)
        V.push_back(num);

    if (num < 0) {
        V.push_back(-1);
        num = num*-1;
    }


    for (int64_t i = 2 ; i <= sqrt(num) ; i++ ){

        while(num % i == 0){
            V.push_back(i);
            num /= i;
        }
    }

    if (num > 1)
        V.push_back(num);

    return V;
}

int64_t strToInt(string arg){

    int64_t num = 0;
    int64_t ten = 1;
    int stop;
    int64_t sign;

    if (arg[0] == '-') {
        sign = -1;
        stop = 1;
    }

    else{
        sign = 1;
        stop = 0;
    }


    for (int i = arg.length()-1 ; i >= stop ; i--){

        if (num + ((int64_t)(arg[i])-48)*ten < 0 ||
            (int64_t)(arg[i]) < 48 || (int64_t)(arg[i]) > 57){

            __throw_invalid_argument("Podano błędną liczbę");
        }

        else{
            num += ((int64_t)(arg[i])-48)*ten;
            ten *= 10;
        }
    }


    return num*sign;
}

int main(int argc, char * argv[]) {



    if (argc == 1){
        cerr << "Wpisz liczby calkowite jako argumenty!" <<  endl;
        return -1;
    }

    else
    {
        string arguments[argc];

        for (int i = 1 ; i < argc ; i++){z
            arguments[i] = argv[i];
        }

        int64_t num;
        vector <int64_t> V;

        for (int i = 1 ; i < argc ; i++)
        {
            num = strToInt(arguments[i]);

            V = primeFactors(num);

            cout << num << " = ";

            bool first = true;

            for (int64_t &factor : V){

                if (first) {
                    cout  << factor;
                    first = false;
                }

                else{
                    cout << "*" << factor;
                }
            }

            cout << endl;
        }
    }

    return 0;
}