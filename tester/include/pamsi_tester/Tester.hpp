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

  protected:
    virtual ResultType runAlgorithm(const InputType& inputData) = 0;
    virtual InputType readSingleInput(std::istream& inputStream) = 0;

  private:
    float runForSingleDataset(const InputType& input,
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

    while(inputStream)
    {
        auto input = readSingleInput(inputStream);

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
    const InputType& input, std::ostream& outputStream, const int testsNum)

{
    Timer timer;
    float execTimeInMs = 0;

    for(auto i = 0; i < testsNum; ++i)
    {
        timer.start();
        outputStream << runAlgorithm(input) << '\n';
        timer.stop();

        execTimeInMs = (execTimeInMs * (i) + timer.msInterval()) /
                       static_cast<float>(i + 1);
    }

    return execTimeInMs;
}

#endif /* TESTER_HPP_ */
