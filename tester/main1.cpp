#include "pamsi_tester/Tester.hpp"
#include "spdlog/spdlog.h"
#include <fstream>
#include <numeric>
#include <vector>

class SumTester : public Tester<int, std::vector<int>>
{
  protected:
    int runAlgorithm(const std::vector<int>& inputData) override;
    std::vector<int> readSingleInput(std::istream& inputStream) override;
};

int SumTester::runAlgorithm(const std::vector<int>& inputData)
{
    return std::accumulate(std::begin(inputData), std::end(inputData), 0,
                           std::plus<int>{});
}


struct Matrix
{
  int nRows, nCols;
  std::vector<float> data;
};


std::ostream& operator<<(std::ostream& output, const Matrix& matrix)
{
  std::ostream_iterator<float> outIterator(output, " ");

  std::copy(matrix.data.begin(), matrix.data.end(), outIterator);

  return output;
}

struct MatrixSumInput
{
  Matrix a;
  Matrix b;
};


class MatrixSumTester: public Tester<Matrix, MatrixSumInput>
{
protected:
  Matrix runAlgorithm(const MatrixSumInput& inputData) override;
  MatrixSumInput readSingleInput(std::istream& inputStream) override;
};


Matrix MatrixSumTester::runAlgorithm(const MatrixSumInput& inputData)
{

  const auto nRows = inputData.a.nRows;
  const auto nCols = inputData.a.nCols;

  Matrix result;

  result.nRows = nRows;
  result.nCols = nCols;

  for(int i = 0; i < nCols*nRows; ++i)
    {
      result.data.push_back(inputData.a.data[i] + inputData.b.data[i]);
    }


  return result;

}


void readToMatrix(std::istream& inputStream, Matrix& matrix, int numOfElements)
{
  for(int i = 0; i < numOfElements; ++i)
    {
      float matrixElement = 0.f;
      inputStream >> matrixElement;

      matrix.data.push_back(matrixElement);
    }
}

MatrixSumInput MatrixSumTester::readSingleInput(std::istream& inputStream)
{
  int nRows = 0, nCols = 0;

  inputStream >> nRows >> nCols;

  MatrixSumInput input;

  input.a.nRows = nRows;
  input.b.nRows = nRows;
  input.a.nCols = nCols;
  input.b.nCols = nCols;

  readToMatrix(inputStream, input.a, nRows*nCols);
  readToMatrix(inputStream, input.b, nRows*nCols);

  return input;
}



std::vector<int> SumTester::readSingleInput(std::istream& inputStream)
{
    int numOfData = 0;

    inputStream >> numOfData;

    std::vector<int> result;

    for(auto i = 0; i < numOfData; ++i)
    {
        int dataElement;
        inputStream >> dataElement;

        result.push_back(dataElement);
    }

    return result;
}

int main(int /*argc*/, char* /*argv*/[])
{
    std::ifstream inputFile{"input.txt"};
    std::ofstream dataOutputFile{"output.txt"}, timeOutputFile{"times.csv"};

    // SumTester tester;
    MatrixSumTester tester;

    if(!inputFile)
    {
        spdlog::error("input.txt cannot be opened!");
        return -1;
    }

    tester.runAllTests(inputFile, dataOutputFile, timeOutputFile);
}
