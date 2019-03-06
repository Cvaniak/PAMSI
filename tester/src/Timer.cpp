#include "pamsi_tester/Timer.hpp"

double Timer::usInterval() const
{
    const double US_PER_NS = 1e-3;
    return nsInterval() * US_PER_NS;
}

double Timer::nsInterval() const
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start)
        .count();
}

double Timer::msInterval() const
{
    const double MS_PER_NS = 1e-6;
    return nsInterval() * MS_PER_NS;
}

double Timer::sInterval() const
{
    const double S_PER_NS = 1e-9;
    return nsInterval() * S_PER_NS;
}

double Timer::precision()
{
    return std::chrono::high_resolution_clock::period::num /
           std::chrono::high_resolution_clock::period::den;
}
