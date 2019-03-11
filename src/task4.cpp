#include "task4.h"

void Task4::ExecuteTask() {
  cout << "Задание 4" << endl;
  Task4 * task = new Task4();
  task->ShowZ();

  cout << "Результат вычисления задания: ";
  cout << task->Result() << endl;

  delete task;
}

void Task4::InitZ() {
  random_device rd;
  mt19937 rng(rd());
  uniform_real_distribution<double> uni(-100.0, 100.0);
  for (size_t i = 0; i < z_.size(); i++) {
    int number = uni(rng);
    z_[i] = move(number);
  }
}


void Task4::ShowZ() {
  for(auto number: z_)
    cout << setw(8) << fixed << setprecision(2) << number;
  cout << endl;
}

double Task4::Result() {
  double result = 0.0;
  for(size_t i=0; i < z_.size(); i++) {
    if (i % 2 == 1) result += z_[i];
    if (i % 3 == 2) result -= z_[i];
  }
  return result;
}
