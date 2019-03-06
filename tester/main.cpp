#include <iostream>

template <typename ResultType, typename InputType>
class Tester
{
  public:
    bool runAllTests(std::istream& inputStream, const int testsNum = 30);
    virtual ~Tester() {}

  protected:
    virtual ResultType runAlgorithm(const InputType& /*inputData*/)
    {
        return ResultType{};
    }
    virtual InputType readSingleInput(std::istream& /*inputStream*/)
    {
        return InputType{};
    };
};

template <typename ResultType, typename InputType>
bool Tester<ResultType, InputType>::runAllTests(std::istream& inputStream,
                                                const int testsNum)
{
    while(inputStream)
    {
        auto input = readSingleInput(inputStream);

        for(auto i = 0; i < testsNum; ++i)
          {
            runAlgorithm(input);
          }
    }

    return true;
}

int main(int argc, char* argv[])
{
    Tester<int, int> tester;
    tester.runAllTests(std::cin);

    return 0;
}
