#include <iostream> // AC(15/15)
#include "function.h"
using namespace std;

Matrix::~Matrix(){
    for(int i=0; i<n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

Matrix::Matrix(int n): n(n){ // matrix is an (n x n) array
    matrix = new long long* [n];
    for(int i=0; i<n; i++)
        matrix[i] = new long long [n];
    this->toZero();
}

Matrix::Matrix(const Matrix& ref): n(ref.n), matrix(ref.matrix){}

Matrix& Matrix::operator=(const Matrix& ref){
    this->n = ref.n;
    matrix = new long long* [n];
    for(int i=0; i<n; i++)
        matrix[i] = new long long [n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            matrix[i][j] = ref.matrix[i][j];
    return *this;
}

long long& Matrix::operator()(const int& row, const int& column) const{
    return this->matrix[row][column];
}

void Matrix::toIdentity(){
    toZero();
    for(int i=0; i<n; i++)
        this->matrix[i][i] = 1;
}

Matrix Matrix::operator*(const Matrix& rhs) const{
    Matrix ans(n);
    for(int row=0; row<n; row++)
        for(int col=0; col<n; col++)
            for(int i=0; i<n; i++){
                ans.matrix[row][col] += (this->matrix[row][i] * rhs.matrix[i][col]) % mod;
                ans.matrix[row][col] %= mod;
            }
    return ans;
}

Matrix Matrix::power(int k) const{
    Matrix init(this->n), ret = *this;
    init.toIdentity();
    while(k > 0){
        if(k % 2 == 1) init = init * ret;
        ret = ret * ret;
        k /= 2;
    }
    return init;
}

Matrix constructMatrix(int n){
    Matrix ret(n);
    for(int i=0; i<n-1; i++)
        ret(i, i+1) = 1;
    for(int col=0; col<n; col++)
        ret(n-1, col) = 1;
    return ret;
}
