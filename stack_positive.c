#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Структура стека
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Инициализация стека
void initStack(Stack *stack) {
    stack->top = -1;
}

// Проверка стека на пустоту
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Проверка стека на переполнение
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Операция push (добавление элемента)
int push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ошибка: стек переполнен!\n");
        return 0;
    }
    stack->data[++stack->top] = value;
    return 1;
}

// Операция pop (удаление и получение элемента)
int pop(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        return 0;
    }
    *value = stack->data[stack->top--];
    return 1;
}

int main() {
    Stack stack;
    int num, poppedValue;
    
    // Инициализируем стек
    initStack(&stack);
    
    printf("Введите последовательность чисел (0 - конец):\n");
    
    while (1) {
        scanf("%d", &num);
        
        // 0 - конец последовательности
        if (num == 0) {
            break;
        }
        
        if (num > 0) {
            // Положительное число - добавляем в стек
            push(&stack, num);
        } else if (num < 0) {
            // Отрицательное число - выводим все положительные из стека в обратном порядке
            printf("Отрицательное число %d. Вывод положительных в обратном порядке:\n", num);
            while (!isEmpty(&stack)) {
                pop(&stack, &poppedValue);
                printf("%d ", poppedValue);
            }
            printf("\n");
        }
    }
    
    // Если после окончания ввода в стеке остались элементы
    if (!isEmpty(&stack)) {
        printf("Оставшиеся положительные числа в обратном порядке:\n");
        while (!isEmpty(&stack)) {
            pop(&stack, &poppedValue);
            printf("%d ", poppedValue);
        }
        printf("\n");
    }
    
    return 0;
}
