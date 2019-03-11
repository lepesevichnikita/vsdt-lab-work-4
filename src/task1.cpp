#include "task1.h"

unsigned int Task1::ColumnWidth = 15;

void Task1::ExecuteTask() {
  cout << "Первое задание" << endl;

  double range_start = CinVariable<double>("начало диапазона");
  double  range_end = CinVariable<double>("конец диапазона");
  double step = CinVariable<double>("шаг вычисления");
  Task1 * task = new Task1(range_start, range_end, step);
  task->ShowResult();

  delete task;
}

template <typename T>
T Task1::CinVariable(const string& variableName, const char& separator) {
  T result;
  cout << "Введите " << variableName << ":" << separator;
  cin >> result;
  cout << endl;
  return result;
}

Task1::Task1(const double& range_start, const double& range_end, const double& step):
  range_start_(range_start), range_end_(range_end), step_(step) {
    BuildXRange();
    CalculateYInRange();
  }

template<typename T>
void Task1::ShowVector(const vector<T>& vec) {
  for(auto const& number: vec)
    cout << setw(ColumnWidth) << number;
  cout << endl;
}

void Task1::ShowHeadOfResult() {
  cout << setw(ColumnWidth) << "x";
  cout << setw(ColumnWidth) << "y(x)";
  cout << setw(ColumnWidth) << "s(x)";
  cout << setw(ColumnWidth) << "|y(x)-s(x)|";
  cout << endl;
}

void Task1::ShowResult() {
  size_t items_count = x_range_.size();
  ShowHeadOfResult();
  for (size_t i = 0; i < items_count; i++) { 
    cout << setw(ColumnWidth) << x_range_[i];
    cout << setw(ColumnWidth) << y_in_range_[i];
    cout << setw(ColumnWidth) << s_range_[i];
    cout << setw(ColumnWidth) << y_minus_s_range_[i];
    cout << endl;
  }
  //ShowVector("x", x_range_);
  //ShowVector("y", y_in_range_);
  //ShowVector("s", s_range_);
  //ShowVector("|y-s|", y_minus_s_range_);
}

void Task1::BuildXRange() {
  x_range_.clear();
  for(double i = range_start_; i<=range_end_; i += step_) {
    x_range_.push_back(i);
  }
}

void Task1::CalculateYInRange() {
  y_in_range_.clear();
  s_range_.clear();
  y_minus_s_range_.clear();
  double prev_y = 0;
  for(const double& x: x_range_) {
    const double current_y = y(x);
    y_in_range_.push_back(current_y);
    s_range_.push_back(prev_y);
    y_minus_s_range_.push_back(current_y - prev_y);
    prev_y = current_y;
  }
}
