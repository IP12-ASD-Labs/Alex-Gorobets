#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int intInput(string);
double** createDoubleMatrix(int, int);
void randMatrixFill(double**, int, int);
double* getColMinArr(double**, int, int);
void arrOutput(double**, int, int, string);
void arrOutput(double*, int, string);
void arrShellsort(double*, int);
void arrDelete(double*);
void arrDelete(double** matrix, int n);


int main()
{   
    setlocale(LC_ALL, "rus");
    
    int n, m;
    
    n = intInput("Enter n: ");
    m = intInput("Enter m: ");

    double** matrix = createDoubleMatrix(n, m);
    randMatrixFill(matrix, n, m);

    double* res_arr = new double[m];
    res_arr = getColMinArr(matrix, n, m);
    
    arrOutput(matrix, n, m, "\nInitial matrix\n");
    arrOutput(res_arr, m, "\nArray of min elements:\n");

    arrShellsort(res_arr, m);

    arrOutput(res_arr, m, "\n\nArray after Shell sort:\n");

    arrDelete(res_arr);
    arrDelete(matrix, n);
}

int intInput(string msg) {
    int n;
    cout << msg;
    cin >> n;
    return n;
}

double** createDoubleMatrix(int n, int m) {
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[m];
    }
    return matrix;
}

void randMatrixFill(double** matrix, int n, int m) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 201 - 100;
        }
    }
}

double* getColMinArr(double** matrix, int n, int m) {
    double min;
    double* res_arr = new double[m];

    for (int j = 0; j < m; j++) {
        min = matrix[0][j];
        for (int i = 0; i < n; i++) {
            if (min > matrix[i][j]) {
                min = matrix[i][j];
            }
        }
        res_arr[j] = min;
    }
    return res_arr;
}

void arrOutput(double** matrix, int n, int m, string msg) {
    cout << msg << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(4) << matrix[i][j];
        }cout << endl;
    }
}

void arrOutput(double* arr, int n, string msg){
    cout<<msg<< endl;
    for (int i = 0; i < n; i++) {   
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

void arrShellsort(double* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i ++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void arrDelete(double* arr) {
    delete[] arr;
}

void arrDelete(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}