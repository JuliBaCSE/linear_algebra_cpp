#include <iostream>
#include <vector>


void print_vec(const std::vector<int> & v)
{
    std::cout << " [ ";
    for (const auto & elem : v)
    {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void print_matrix(const std::vector<std::vector<int>> & A)
{
    std::cout << "[" << std::endl;
    for (const auto & row : A)
    {
        for (const auto & elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

int main() {

    std::vector<std::vector<int>> A = { {1 , 2},
                                        {3 , 4}};
    std::vector<int> v = { 1 , 1};

    auto N = v.size();

    // Print the matrix A
    std::cout << "Matrix A is:" << std::endl;
    print_matrix(A);

    // print vector v
    std::cout << "Vector V is:" << std::endl;
    print_vec(v);

    // Multiply v * A and store it to a vector m
    std::vector<int> m(N, 0);
    for (auto i=0; i<N; ++i)
    {
        for (auto j=0; j<N; ++j)
        {
            m[j] += v[i]*A[i][j];
        }
    }

    // Print the vector m
    std::cout << "Vector m = v * A is:" << std::endl;
    print_vec(m);

    return 0;
}
