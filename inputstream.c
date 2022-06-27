#include <stdio.h>
#include <string.h>

#define LEN 256
#define LEN80 80

int f1(void) {
  int c, space, tab, enter;

  space = tab = enter = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      space++;
    if (c == '\t')
      tab++;
    if (c == '\n')
      enter++;
  }
  printf("sum_space = %d\nsum_tab = %d\nsum_enter = %d\n", space, tab, enter);
  return 0;
}

void f2(void) {
  char c;
  printf("\n");
  FILE *S;
  S = fopen("stream.txt", "w+");
  if (!S) {
    printf("Error\n");
    return;
  }

  while ((c = getchar()) != EOF) {
    if ((c != ' ') && (c != '\t') && (c != '\n') && (c != EOF)) {
      fprintf(S, "%c", c);
    } else
      fprintf(S, "\n");
  }
  fclose(S);
  S = fopen("stream.txt", "r+");
  if (!S) {
    printf("Error\n");
    return;
  }
  while ((c = fgetc(S)) != EOF) {
    printf("%c", c);
  }
  fclose(S);
}

void f3(void) {
  char c;
  int i;
  int lengths[1000] = {0};
  int cnt = 0;
  while ((c = getchar()) != EOF) {
    if ((c != ' ') && (c != '\t') && (c != '\n')) {
      cnt++;
      if (cnt >= 1000) {
        printf("Слово не может быть длиннее 1000 символов.");
        return;
      }
    } else {
      lengths[cnt] += 1;
      cnt = 0;
    }
  }

  printf("\n");
  for (i = 1; i < 1000; i++) {
    if (lengths[i] != 0)
      printf("Слов длиной %i - %i\n", i, lengths[i]);
  }
}

void f4(void) {
  char c;
  char s[81] = {0};
  int cnt = 0;
  int i;

  FILE *S;
  S = fopen("stream.txt", "w+");
  if (!S) {
    printf("Error\n");
    return;
  }
  printf("\n");
  while ((c = getchar()) != EOF) {
    if ((c != '\n') && (c != EOF)) {
      if (cnt < 81) {
        s[cnt] = c;
      } else if (cnt == 81) {
        fprintf(S, "%s", s);
      } else if (cnt > 81) {
        fprintf(S, "%c", c);
      }
      cnt += 1;
    } else {
      cnt = 0;
      for (i = 0; i < 81; i++) {
        s[i] = 0;
      }
      fprintf(S, "\n");
    }
  }
  fclose(S);
  S = fopen("stream.txt", "r+");
  if (!S) {
    printf("Error\n");
    return;
  }
  while ((c = fgetc(S)) != EOF) {
    printf("%c", c);
  }
  fclose(S);
}

void reverse(char *s, char *res, int length) {
  int i;
  for (i = 0; i < length; i++) {
    res[length - 1 - i] = s[i];
  }
}

void f5(void) {
  char c;
  printf("\n");
  char s[LEN] = {0};
  char res[LEN] = {0};
  FILE *S;
  S = fopen("stream.txt", "w+");
  if (!S) {
    printf("Error\n");
    return;
  }

  while ((c = getchar()) != EOF) {
    fprintf(S, "%c", c);
  }
  fclose(S);
  S = fopen("stream.txt", "r+");
  if (!S) {
    printf("Error\n");
    return;
  }
  printf("\n");
  while (fgets(s, LEN, S) != NULL) {

    reverse(s, res, strlen(s));

    printf("%s", res);

    int i;

    for (i = 0; i < LEN; i++) {
      res[i] = 0;
      s[i] = 0;
    }
  }
  fclose(S);
}

int main() { f5(); }
