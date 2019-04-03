#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer
{
  public:
    double nsInterval() const;
    double usInterval() const;
    double msInterval() const;
    double sInterval() const;

    static double precision();

    void start() { m_start = std::chrono::high_resolution_clock::now(); }

    void stop() { m_end = std::chrono::high_resolution_clock::now(); }

  private:
    std::chrono::high_resolution_clock::time_point m_start;
    std::chrono::high_resolution_clock::time_point m_end;
};

#endif /* TIMER_HPP */
