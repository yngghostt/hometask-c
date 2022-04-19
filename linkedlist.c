#include <stdio.h>
#include <stdlib.h>

typedef struct NODE LIST;

struct NODE
{
  int Data;
  LIST *Next;
};

int CreateFirstElement( LIST **L, int NewData )                    
{
  LIST *NewElement;
  NewElement = malloc(sizeof(LIST));

  if(NewElement == NULL)
    return 0; 
    
  NewElement -> Data = NewData;                              
  NewElement -> Next = *L;
  *L = NewElement;                                            
  return 1; 
}      

int AddToListEnd( LIST **L, int value )
{
  LIST *NewElement;
  NewElement = malloc(sizeof(LIST));
  int *NewData = &value;

  if(NewElement == NULL)
    return 0; 

  NewElement->Data = *NewData;                              
  NewElement->Next = NULL;
  while (*L != NULL)
    L = &((*L) -> Next);
  *L = NewElement;
  return 1;
}

int DelFromListEnd( LIST **L )
{
  if (*L == NULL)
    return 1;
  
  while ((*L) -> Next != NULL)
    L = &(*L) -> Next;
  *L = NULL;
  return 0;
}


void DisplayList( LIST *L )
{
  if(L == NULL)
    printf("<Empty List>\n");
  else
    while (L != NULL)
    {
      printf("%i", L->Data);
      L=L->Next;
      if(L == NULL)
        printf("\n");
      else
        printf(", ");
    }
}

void ClearList( LIST **L )
{
  *L = NULL;
}

int Search( LIST *L, int value )
{
  if(L == NULL)
    return 0;
  else
    while (L != NULL)
    {
      if(L->Data == value)
        return 1;
      else
        L = L->Next;
    }
    return 0;
}

int main( void ) 
{
  LIST *list = NULL;
  int value, res, run = 1;
  char input;

  while (run)
  {
    printf("--------------------\n");
    printf("0 - Выход\n");
    printf("1 - Создать первый элемент списка\n");
    printf("2 - Добавить элемент в конец списка\n");
    printf("3 - Удалить элемент с конца списка\n");
    printf("4 - Вывести список на экран\n");
    printf("5 - Удалить весь список\n");
    printf("6 - Выполнить поиск элемента в списке\n");
    printf("--------------------\n");
    scanf("%c", &input);
    switch (input)
    {
      case '0':
        run = 0;
        break;

      case '1':
        printf("Введите значение:\n");
        scanf("%d", &value);
        res = CreateFirstElement(&list, value);
        if(res)
          printf("Элемент создан\n");
        else
          printf("Произошла ошибка\n");
        break;

      case '2':
        printf("Введите значение:\n");
        scanf("%d", &value);
        res = AddToListEnd(&list, value);
        if(res)
          printf("Элемент добавлен\n");
        else
          printf("Произошла ошибка\n");
        break;

      case '3':
        res = DelFromListEnd(&list);
        if(res)
          printf("Элемент удалён\n");
        else
          printf("Произошла ошибка\n");
        break;

      case '4':
        printf("Элементы списка:\n");
        DisplayList(list);
        break;

      case '5': 
        ClearList(&list);
        printf("Список очищен\n");
        break;

      case '6':
        printf("Введите элемент для поиска:\n");
        scanf("%d", &value);
        res = Search(list, value);
        if(res)
          printf("Элемент есть списке\n");
        else
          printf("Элемента нет в списке\n");
        break;
        
      default:
        printf("Команда не распознана\n");
        break;     
     } 
  }

    return 0;
}
