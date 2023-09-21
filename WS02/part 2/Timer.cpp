#include<iostream>
#include<chrono>
#include "Timer.h"
using namespace std;
namespace sdds {
void Timer::start() {
    m_start = std::chrono::steady_clock::now();
}

long long Timer::stop() {
    m_end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start).count();
}
}

