#include "task3.h"

Task3::Task3(const unsigned int& size):
  size_(size) {
    InitX();
  }

void Task3::ExecuteTask() {
  unsigned int size;
  cout << "Введите длину массива (<=500): "; cin >> size; cout << endl;

  size = size % 501;

  Task3 * task = new Task3(size);

  task->ShowX();

  task->ShowHist();
  cout << "MX: " << task->AverageOfX() << endl;
  cout << "DX: " << task->DX() << endl;
  cout << "h: " << Task3::H() << endl;

  delete task;
}

void Task3::InitX() {
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> uni(kXMin, kXMax);
  for (unsigned int i = 0; i < size_; i++) {
    int number = uni(rng);
    ++hist_[RangeByNumber(number)];
    x_.push_back(number);
  }
}

void Task3::ShowHist(){
  for(size_t i = 0; i < 10; i++) {
    string hist_line(hist_[i], '|');
    double range_start = kXMin+i*H();
    double range_end = range_start + H();
    cout << setw(4) << i+1 << ' ';
    cout << fixed << setw(10) << setprecision(2);
    cout << range_start << '-' << range_end << ':';
    cout << hist_line << endl;
  }
}

void Task3::ShowX() {
  cout << setw(5) << "Xi" << endl;
  for(auto number: x_) {
    cout << setw(5) << number << endl;
  }
}
