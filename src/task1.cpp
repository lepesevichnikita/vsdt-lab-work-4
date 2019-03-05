#include "task1.h"

void Task1::ExecuteTask() {
  double range_start, range_end, step;
  cout << "Введите начало диапазона: ";
  cin >> range_start;
  cout << endl;

  cout << "Введите конец диапазона: ";
  cin >> range_end;
  cout << endl;

  cout << "Введите шаг вычисления: ";
  cin >> step;
  cout << endl;

  Task1 * task = new Task1(range_start, range_end, step);
  task->ShowYInRange();

  delete task;
}

Task1::Task1(const double& range_start, const double& range_end, const double& step):
  range_start_(range_start), range_end_(range_end), step_(step) {
    BuildXRange();
    CalculateYInRange();
  }

void Task1::ShowVector(const string& start, const vector<double>& vec) {
  cout << setw(5) << start << '|';
  for(double const& number: vec)
    cout << setw(5) << number;
  cout << endl;
}

void Task1::ShowYInRange() {
  ShowVector("x", x_range_);
  ShowVector("y", y_in_range_);
  ShowVector("s", s_range_);
  ShowVector("|y-s|", y_minus_s_range_);
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
