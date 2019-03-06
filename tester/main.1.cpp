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

std::vector<int> SumTester::readSingleInput(std::istream& inputStream)
{
    int numOfData = 0;

    inputStream >> numOfData;

    std::vector<int> result;
    result.reserve(numOfData);

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

    SumTester tester;

    if(!inputFile)
    {
        spdlog::error("input.txt cannot be opened!");
        return -1;
    }

    tester.runAllTests(inputFile, dataOutputFile, timeOutputFile);
}
