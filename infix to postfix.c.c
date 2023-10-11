#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct stack{
    int size;
    int top;
    char *oper;
    
};

int precedence(struct stack *ptr,char x){
    if ( x== '(' || x== ')' ){
        return 3;
    }
    else if ( x== '*' || x== '/' ){
        return 2;
    }
    
    else if ( x== '+' || x== '-' ){
        return 1;
    }
    else{
        return 0;
    }
    
}



int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
    return 0;
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;   
}

void push(struct stack *ptr,char x){
    if(isFull(ptr)){
        printf("stack overflow");
    }
    else{
    ptr->top++;
    ptr->oper[ptr->top]=x;
    
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        return 0;
    }
    char x=ptr->oper[ptr->top];
    ptr->top--;
    return x;
}

char* intopost(char *infix){
    struct stack *sp=(struct stack*) malloc (sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->oper= (char*) malloc (sp->size*sizeof(char));
    
    char *postfix= (char*) malloc (strlen(infix)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(!precedence(sp,infix[i])){   //checking whether it is an operator or not
            postfix[j]=infix[i];
            i++,j++;
        }
        else{
            if(sp->top==-1 || precedence(sp,infix[i])>precedence(sp,sp->oper[sp->top])){
                push(sp,infix[i]);
                i++;
            }   
            else{
                postfix[j]=pop(sp);
                j++;
                }
            
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char *infix="x-y";
    printf("%s",intopost(infix));
    return 0;

}