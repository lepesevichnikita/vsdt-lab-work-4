#ifndef LAB4_INCLUDE_TASK4_H
#define LAB4_INCLUDE_TASK4_H

#include <iostream>
#include <random>
#include <array>
#include <iomanip>

using namespace std;

class Task4 {
  public:

    static void ExecuteTask();

    Task4() {
      InitZ();
    }

    double Result();
    void ShowZ();

  private:
    array<double, 16> z_;
    void InitZ();

};

#endif
