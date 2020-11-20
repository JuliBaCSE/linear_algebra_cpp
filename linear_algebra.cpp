#include <iostream>
#include <vector>


template <typename VarTypeVec>
void printRowVec(const std::vector<VarTypeVec> & v)
{
    std::cout << " [ ";
    for (const auto & elem : v)
    {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename VarTypeVec>
void printColVec(const std::vector<VarTypeVec> & v)
{
    std::cout << " [ " <<std::endl;
    for (const auto & elem : v)
    {
        std::cout << elem << std::endl;
    }
    std::cout << "]" << std::endl;
}


template <typename VarTypeMa>
void printMatrix(const std::vector<std::vector<VarTypeMa> > & A)
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

template<typename VarTypeMultResult>
void vectorMatrixProduct(const std::vector<std::vector<VarTypeMultResult> > &A, const std::vector<VarTypeMultResult> &v){
    auto N = v.size();

    // Print the matrix A
    std::cout << "Matrix A is:" << std::endl;
    printMatrix(A);

    // print vector v
    std::cout << "Vector V is:" << std::endl;
    printRowVec(v);



    // Multiply v * A and store it to a vector m
    std::vector<VarTypeMultResult> m(N, 0);
    for (auto i=0; i<N; ++i)
    {
        for (auto j=0; j<N; ++j)
        {
            m[j] += v[i]*A[i][j];
        }
    }
    // Print the vector m
    std::cout << "Vector m = v * A is:" << std::endl;
    printVec(m);
}

template<typename VarType>
std::vector<VarType> operator*(const std::vector<std::vector<VarType> > &A, const std::vector<VarType> &v){
    
    //check num col
    
    assert(A[0].size()== v.size());
    std::vector<VarType>results;
    VarType result = 0;
    for (auto &row: A) {
        result = 0;
        unsigned int count= 0;
		for (auto &e: row) {
            result += e * v[count];
            count++;
		}
        results.push_back(result);
	}
    return results;
}

//Test function
bool testMatrixVectorProduct(const std::vector<int> &vec){
    std::vector<int> reference = {1,-3};

    for(auto i = 0; i<vec.size();i++){
        if(vec[i]!= reference[i]){
            std::cout << "There seems to be an error" << std::endl;
            printColVec(reference);
            printColVec(vec);

            return false;
        }
    }
    std::cout << "all fine";
    return true;
}

int main() {

    std::vector<std::vector<int> > A = { {1 , -1, 2},
                                        {0 ,-3, 1}};
    std::vector<int> v = { 2, 1,0};
    //vectorMatrixProduct(A,v);

    printColVec(A*v);

    testMatrixVectorProduct(A*v);
    return 0;
}
