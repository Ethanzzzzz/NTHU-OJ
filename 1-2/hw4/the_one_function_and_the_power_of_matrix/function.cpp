#include <iostream> // AC(15/15)
#include "function.h"
using namespace std;

Matrix::~Matrix(){
    for(int i=0; i<this->n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

Matrix::Matrix(int n){ // matrix is an (n x n) array
    this->n = n;
    this->matrix = new long long *[n];
    for(size_t i=0; i<n; i++)
        this->matrix[i] = new long long [n];
    this->toZero();
}

Matrix::Matrix(const Matrix& ref){
    this->n = ref.n;
    this->matrix = ref.matrix;
}

Matrix& Matrix::operator=(const Matrix& ref){
    this->n = ref.n;
    this->matrix = new long long *[n];
    for(size_t i=0; i<n; i++) this->matrix[i] = new long long [n];

    for(size_t i=0; i<n; i++)
        for(size_t j=0; j<n; j++)
            this->matrix[i][j] = ref.matrix[i][j];
    return *this;
}

long long& Matrix::operator()(const int& row, const int& column) const{
    return this->matrix[row][column];
}

void Matrix::toIdentity(){
    this->toZero();
    for(size_t i=0; i<this->n; i++)
        this->matrix[i][i] = 1;
}

Matrix Matrix::operator*(const Matrix& rhs) const{ // 矩陣乘法 在(i, j)的值 等於前面的ith列 * 後面的jth行(直行橫列)
    Matrix ans(n);
    ans.toZero();
    for(size_t row=0; row<n; row++)
        for(size_t col=0; col<n; col++)
            for(size_t i=0; i<n; i++){
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
    Matrix ans(n);
    ans.toZero();
    for(size_t i=1; i<n; i++) // 所以這樣是可以改掉的喔 好色
        ans(i-1, i) = 1;
    for(size_t i=0; i<n; i++)
        ans(n-1, i) = 1;
    return ans;
}
