// performance_evaluation.h

#ifndef PERFORMANCE_EVALUATION_H
#define PERFORMANCE_EVALUATION_H

#include <chrono>

class Timer {
public:
    Timer() : start_(std::chrono::high_resolution_clock::now()) {}
    void reset() { start_ = std::chrono::high_resolution_clock::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<std::chrono::duration<double>>(
                   std::chrono::high_resolution_clock::now() - start_)
            .count();
    }

private:
    std::chrono::high_resolution_clock::time_point start_;
};

#endif // PERFORMANCE_EVALUATION_H
