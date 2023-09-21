// Devon Connelly
// 105322218
// dconnelly@myseneca.ca
// Sep. 20 2023
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include<chrono>
namespace sdds {
class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> m_start;
    std::chrono::time_point<std::chrono::steady_clock> m_end;
public:
    void start();
    long long stop();
};
}
#endif /* Timer_h */
