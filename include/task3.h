#ifndef LAB4_INCLUDE_TASK3_H
#define LAB4_INCLUDE_TASK3_H

#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <map>
#include <math.h>
#include <functional>
#include <iomanip>

using namespace std;

class Task3 {
  public:
    static const int kXMin = 3;
    static const int kXMax = 68;
    static inline double H() {
      return (kXMax - kXMin + 1)/10.0;
    }

    static inline int RangeByNumber(const int& number) {
      return (number - kXMin)/H();
    }

    static void ExecuteTask();

    Task3(const unsigned int&);

    void ShowHist();

    inline double AverageOfX() const {
      return accumulate(next(x_.begin()), x_.end(), x_.front())/size_;
    }


    inline double DX() const {
      double avg = AverageOfX();
      auto dx = [&](int a, int b) {
                         return pow(std::move(a) + avg, 2);
                     };
      return accumulate(next(x_.begin()), x_.end(), pow(x_.front()+avg, 2), dx)/size_;
    }

  private:
    vector<int> x_;
    unsigned int size_;
    map<int, int> hist_;

    void InitX();
    void ShowX();
};

#endif
