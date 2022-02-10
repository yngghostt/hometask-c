#include <stdio.h>

// Задание 1
void task1(void) {
  printf("Введите по очереди 5 чисел\n");
  int x1, x2, x3, x4, x5;
  scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5);
  double mean = (x1 + x2 + x3 + x4 + x5) / 5.0; 
  printf("Результат: %.3lf\n", mean);
}

// Задание 2
void task2(void) {
  int n;
  printf("Введите число\n");
  scanf("%d", &n);
  if(n % 2 == 0)
    printf("Введённое число чётное\n");
  else
    printf("Введённое число нечётное\n"); 
  
}

// Задание 3
void task3(void) {
  int age;
  printf("Введите Ваш возраст в годах\n");
  scanf("%d", &age);
  printf("Вам %d лет или %d дней\n", age, age*365);
}

// Задание 4
void task4(void){
  int toes = 10;
  printf("toes = %d\ntoes*2 = %d\ntoes^2 = %d\n", toes, 2*toes, toes*toes);
}

// Задание 5
void task5(void) {
  int growth;
  printf("Введите Ваш рост в сантиметрах\n");
  scanf("%d", &growth);
  printf("Ваш рост в дюймах: %.2lf\n", growth / 2.54);
}

int main(void) {
task1();
task2();
task3();
task4();
task5();
return 0;
}