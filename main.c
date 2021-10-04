#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    printf("Input the size of the stack : ");
    scanf("%d",&st->size);
    st->top = -1;
    st->S = (int *)malloc(sizeof(int) * st->size);
}
void display(struct Stack st){
    for(int i=st.top;i>=0;i--){
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int element){
    if(st->top == st->size-1){
        printf("Stack Overflow\n");
        return;
    }
    st->top++;
    st->S[st->top] = element;
}
int pop(struct Stack *st){

    if(st->top == -1)
        return -1;
    return st->S[st->top--];
}

bool isEmpty(struct Stack st){
    if(st.top == -1)
        return true;
    return false;
}
int topElement(struct Stack st){
    if(isEmpty(st))
        return -1;
    return st.S[st.top];
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 30);
    push(&st, 50);
    printf("Top of the element is : %d\n", topElement(st));
    display(st);
    return 0;
}
