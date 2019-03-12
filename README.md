# Лабораторная работы по предмету "Визуальные средства разработки программных приложений"

## Задание 1
- Заголовоный файл: *include/task1.h*
- Реализация: *src/task1.cpp*

Вычислить значения функции Y(x), S(x) на заданном промежутке с заданным шагом.
Вывести результат вычисления в виде таблице, также и |Y(x)-S(x)|.

![Условие функции](docs/function.png "Условие функции")

## Задание 2
Результаты первого задания (набор значений X, значений функций S(x) и Y(x) от соответствующих значений Xi) в динамиеский коллекциях, векторах.

Нет отдельной реализации, совмещено с первым заданием.

## Задание 3
- Заголовоный файл: *include/task3.h*
- Реализация: *src/task3.cpp*
Создать массив длинной <= 500.
Заполнить случайными числами в диапазоне от kXMin до kXMax.
Посчитать колличество вхождений эллементов массива в каждый из 10 диапозонов на промежутке kXMin до kXMax с шагом H=(kXMin-kXMax+1)/10.
Вывести гистограмму, среднее значение элементов массива(MX), дисперсию(DX).

## Задание 4
- Заголовоный файл: *include/task4.h*
- Реализация: *src/task4.cpp*

Дан массив вещественных чисел Z(16).
Вычислить разность суммы четных элементов массива и суммы элементов массива, чьи индексы кратны трём.
