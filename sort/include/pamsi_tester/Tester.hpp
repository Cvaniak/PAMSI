#ifndef TESTER_HPP_
#define TESTER_HPP_

#include "pamsi_tester/Timer.hpp"
#include "spdlog/spdlog.h"
#include <iostream>

template <typename ResultType, typename InputType>
class Tester
{
  public:
    void runAllTests(std::istream& inputStream, std::ostream& dataOutputStream,
                     std::ostream& timeOutputStream, const int testsNum = 10);
    virtual ~Tester() {}
    virtual InputType readSingleInput(std::istream& inputStream) = 0;

  protected:
    virtual ResultType runAlgorithm(InputType& inputData) = 0;

  private:
    float runForSingleDataset(InputType& input,
                              std::ostream& outputStream, const int testsNum);
};

template <typename ResultType, typename InputType>
void Tester<ResultType, InputType>::runAllTests(std::istream& inputStream,
                                                std::ostream& outputStream,
                                                std::ostream& timeOutputStream,
                                                const int testsNum)
{
    spdlog::info("Running tests");

    auto datasetIndex = 0;

    constexpr auto SEPARATOR = ";";

    timeOutputStream << "dataset_num" << SEPARATOR << "avg_time\n";

    while(!inputStream.eof())
    {
    std::cout << "d" << std::endl;
        auto input = readSingleInput(inputStream);

    std::cout << "e" << std::endl;
        if(inputStream)
        {
            spdlog::info("Next dataset processing {}", datasetIndex);

            auto averageTimeInMs =
                runForSingleDataset(input, outputStream, testsNum);

            timeOutputStream << datasetIndex << SEPARATOR << averageTimeInMs
                             << '\n';

            spdlog::info(
                "Dataset {} processed successfully. Average Time: {} [ms]",
                datasetIndex, averageTimeInMs);
        }

        ++datasetIndex;
    }

    spdlog::info("Testing finished");
}

template <typename ResultType, typename InputType>
float Tester<ResultType, InputType>::runForSingleDataset(
    InputType& input, std::ostream& outputStream, const int testsNum)

{
    Timer timer;
    float execTimeInMs = 0;
    // std::vector<int> (tab);

    for(auto i = 0; i < testsNum; ++i)
    {
        timer.start();
        runAlgorithm(input);
        timer.stop();

        execTimeInMs = (execTimeInMs * (i) + timer.msInterval()) /
                       static_cast<float>(i + 1);
    }

    // int k =0;
    // while(k<input.size()-1){
    //     outputStream << input[k] << " ";
    //     k++;
    // }
    outputStream << input.size()<<std::endl;
    std::cout << "c" << std::endl;

    return execTimeInMs;
}

#endif /* TESTER_HPP_ */
