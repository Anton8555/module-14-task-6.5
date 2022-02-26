#include <iostream>
#include <vector>

/*!
 * @brief Output of a two-dimensional square matrix in tabular form.
 * @param matrix - original matrix.
 * @param n - matrix dimension.
 */
void matrixPrint(std::vector<std::vector<double>> matrix, int n)
{
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout.width(7);
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<double>> matrix;
    int n, new_n, di;

    // matrix input
    std::cout << "Enter matrix size:";
    std::cin >> n;
    std::cout << "Enter matrix elements:";
    matrix.resize(n);
    for(int i=0; i<n; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];
    }

    // matrix source output
    std::cout
            << std::endl
            << "Matrix source:\n"
            << "Size = " << n << std::endl;
    matrixPrint(matrix, n);

    // task: matrix transformation
    di = new_n = n*n;
    matrix.resize(di);
    for(int i=(n-1); i>=0; i--)
        for (int j=(n-1); j>=0; j--) {
            matrix[--di].resize(new_n);
            double temp = matrix[i][j];
            matrix[i][j] = 0;
            matrix[di][di] = temp;
    }

    // output of the modified matrix
    std::cout
        << std::endl
        << "The modified matrix:\n"
        << "Size = " << new_n << std::endl;
    matrixPrint(matrix, new_n);

    return 0;
}
