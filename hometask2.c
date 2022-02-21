#include <stdio.h>
#include <limits.h>

void task1(void) {
  int n, next, sum = 0;
  scanf("%d", &n);
  if(n <= 0)
    return;
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &next);
    sum += next;
  };
  printf("Сумма: %d\n", sum);
}

void task2(void) {
  int n, next, min = INT_MAX;
  scanf("%d", &n);
  if(n <= 0)
    return;
  int i;
  for(i = 0; i < n; i++) {
    scanf("%d", &next);
    if(next < min)
      min = next;
  };
  printf("Минимальный элемент: %d\n", min);
}

void task3(void) {
  int count = 0, sum = 0, next;
  printf("Введите последовательность\n");
  while((scanf("%d", &next)) & (next != EOF)) {
    count++;
    sum += (int)next;
  }
  printf("Элементов: %d\nСумма: %d\n", count, sum);
}

void task4(void) {
  int k, count = 1, first = -1, next;
  printf("Введите k\n");
  scanf("%d", &k);
  printf("Введите последовательность\n");
  while((scanf("%d", &next)) & (next != EOF)) {
    if((k < (int)next) & (first == -1))
      first = count;
    count++;
  }
  printf("Первый элемент >k:  %d\n", first);
}

void task5(void) {
  int prev = INT_MIN, input, increases = 1;
  printf("Введите последовательность\n");
  while((scanf("%d", &input)) & (input != EOF)) { 
      if(prev >= input) 
        increases = 0;
       prev = input;
  }
  if(increases == 1)
    printf("Последовательность возрастающая\n");
  else
   printf("Последовательность не возрастающая\n");
}

void task6(void) {
  int left = INT_MIN, cur, count = 0, i = 1;
  printf("Введите последовательность\n");
  while((scanf("%d", &cur)) & (cur != EOF)) {
    if(left > cur) {
      count++;
      printf("Элемент под номером %d меньше своего левого соседа\nТаких элементов в последовательности: %d\n", i, count);
    }
    i++;
    left = cur;
  }  
}

void task7(void) {
  int min = INT_MAX, num, count = 0, input;
  printf("Введите последовательность\n");
  while((scanf("%d", &input)) & (input != EOF)) {
    if (input < min) {
      min = input;
      num = count;
    }
    count++;
  }
  printf("Перед первым минимальным элементом %d элемента(ов)\n", num);
}

void task8(void) {
  int input, count = 0, max = 0;
  printf("Введите последовательность\n");
  while((scanf("%d", &input)) & (input != EOF)) {
    if (input % 2 == 0) {
      count++;
    } else {
      if (max < count){
        max = count;
      }
      count = 0;
    }
  }
  printf("Максимальное количество чётных элементов, идущих подряд: %d\n", max);
}

void task9(void) {
  int left = INT_MIN, cur, count_odd = 0, count_even = 0;
  printf("Введите последовательность\n");
  while((scanf("%d", &cur)) & (cur != EOF)) {
    if (cur % 2 == 0){
      count_even++;
      if (left % 2 == 1 & left != INT_MIN) {
        printf("Длина последовательности нечётных чисел: %d\n", count_odd);
        count_odd = 0;
      }
    } else {
      count_odd++;
      if (left % 2 == 0 & left != INT_MIN) {
        printf("Длина последовательности чётных чисел: %d\n", count_even);
        count_even = 0;
      }
    }
    left = cur;
  }
}

void task10(void) {
  int left = INT_MIN, cur, count_enc;
  printf("Введите последовательность\n");
  while((scanf("%d", &cur)) & (cur != EOF)) {
    if (left > cur) {
      count_enc++;
    }
    left = cur;
  }
  printf("Число участков возрастания: %d\n", count_enc);
}

void task11(void) {
  int prev = INT_MIN, left = INT_MIN, cur, cur_prev, cur_count = 0, max_prev = 0, max_count = 0;
  printf("Введите последовательность\n");
  while((scanf("%d", &cur)) & (cur != EOF)) {
    if (left == cur) {
      if (prev != cur){
        cur_prev = prev;
      }
      cur_count++;
    } else {
      if (cur_count + 1 > max_count) {
        max_count = cur_count + 1;
        max_prev = cur_prev;
      }
      cur_count = 0;
    }
    prev = left;
    left = cur;
    
  }
  printf("Элементов в самом длинном участке из одинаковых чисел: %d\nЭлемент перед участном: %d\n", max_count, max_prev);
}
    

int main(void) {
  task1();
  task2();
  task3();
  task4();
  task5();
  task6();
  task7();
  task8();
  task9();
  task10();
  task11();
  return 0;
}
