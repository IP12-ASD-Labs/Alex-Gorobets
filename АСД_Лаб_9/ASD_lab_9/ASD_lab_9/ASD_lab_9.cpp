#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int intInput(string);
double** createMatrix(int, int);
void displayMatrix(double**, int, int, string);
void randMatrixInput(double**, int, int);
void findColumnMaxAndSwap(double**, int, int);

int main()
{
    setlocale(LC_ALL, "rus");

    int m, n;
    m = intInput("Enter m: ");
    n = intInput("Enter n: ");

    double** matrix = createMatrix(m,n);

    randMatrixInput(matrix, m, n);
    displayMatrix(matrix, m, n, "\nInitial matrix:\n");
    
    findColumnMaxAndSwap(matrix, m, n);
    displayMatrix(matrix, m, n, "\nResult matrix:\n");
}

int intInput(string msg)
{
    int n;
    cout << msg;
    cin >> n;
    return n;
}

double** createMatrix(int m, int n)
{   
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new double[n];
    }
    return matrix;
}

void displayMatrix(double** matrix, int m, int n, string msg)
{
    cout << msg;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }cout << endl;
}

void randMatrixInput(double** matrix, int m, int n)
{
    srand(time(NULL));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            matrix[i][j] = rand() % (201) - 100;
        }
    }
}

void findColumnMaxAndSwap(double** matrix, int m, int n) {
    int indexI;
    for (int j = 0; j < n; j++) {
        indexI = 0;
        double max = matrix[0][j];
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] >= max) {
                max = matrix[i][j];
                indexI = i;
            }
        }
        
        int maxJ = j;
        double resMax = max;
        cout << "Max element of "<< maxJ <<" column: " << resMax << "\tPosition: " << indexI << " " << maxJ << endl;
        
        double temp = matrix[indexI][j];
        matrix[indexI][j] = matrix[indexI][0];
        matrix[indexI][0] = temp;
    }
}
