#include <ctime>
#include <iostream>

using namespace std;

const int SIZE = 10;

void fillArrays(char* , char*);
void thirdArrFill(char*, char*, char*);
int countRes(char*);
void charArrOutput(char*, string);


int main()
{
    setlocale(LC_ALL, "rus");
    char arr1[SIZE], arr2[SIZE], arr3[SIZE] = {0};

    fillArrays(arr1, arr2);
    thirdArrFill(arr1, arr2, arr3);

    charArrOutput(arr1, "First arr elements:");
    charArrOutput(arr2, "Second arr elements:");
    charArrOutput(arr3, "Third arr elements:");
    
    cout << "Result: " << countRes(arr3)<<endl;

}


void charArrOutput(char* arr, string msg) {
    cout << msg << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void fillArrays(char* arr1, char* arr2) {
    for (int i = 0; i < SIZE; i++) {
            arr1[i] = 100 + i;
            arr2[i] = 110 - i * i;
    }   
}

void thirdArrFill(char* arr1, char* arr2, char* arr3) {
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr1[i] == arr2[j]) {
                arr3[k] = arr1[i];
                k++;
            }
        }
    }
}


int countRes(char* arr3) {
    int res = 1;
    for (int i = 0; i<SIZE; i++) {
        if(arr3[i]!=0)
            res *= int(arr3[i]);
    }
    return res;
}