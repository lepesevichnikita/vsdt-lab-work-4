#ifndef LAB4_INCLUDE_TASK1_H
#define LAB4_INCLUDE_TASK1_H

#include <iostream>
#include <functional>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

class Task1 {
  public:
    static unsigned int ColumnWidth;

    Task1(const double& , const double&, const double&);

    inline vector<double> GetYInRange() const {
      return y_in_range_;
    }

    void ShowResult();

    static void ExecuteTask();

    static double inline DegressToRad(const double& degrees) {
      return degrees*M_PI/180;
    }

    static inline double y(const double& x) {
      return x-3*pow(cos(DegressToRad(1.04*x)), 2);
    }

  protected:
    template <typename T>
    static T CinVariable(const string&, const char& separator=' ');

  private:
    double range_start_, range_end_, step_;
    vector<double> y_in_range_;
    vector<double> x_range_;
    vector<double> s_range_;
    vector<double> y_minus_s_range_;

    void BuildXRange();
    void CalculateYInRange();
    void ShowHeadOfResult();

    template <typename T>
    void ShowVector(const vector<T>&);
};

#endif
