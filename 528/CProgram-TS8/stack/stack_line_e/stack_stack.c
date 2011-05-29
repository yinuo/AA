/* stack stack */

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 128
#define STACK_INC  32

//////////////////////////////////////////////////////////////////////
typedef  struct
{
    char *base;
    char *top;
    int  ssize;
}SqStack;

/*********************************************************************
* Create Stack
**********************************************************************/
int StackCreate(SqStack *s)
{
    s->base = (char*)malloc(STACK_SIZE*sizeof(char));
    if(!s->base)
    {
    	  printf("StackCreate()->malloc() failure! \n");
        exit(0);
    }

    s->top = s->base;
    s->ssize = STACK_SIZE;
    return 0;
}

/*********************************************************************
* Push Stack
**********************************************************************/
int StackPush(SqStack *s, char e)
{
    if((s->top - s->base) >= s->ssize)
    {
        s->base = (char*)realloc(s->base, (s->ssize + STACK_INC)*sizeof(char));
        if(!s->base)
        {
        	  printf("StackPush()->realloc() failure!!!\n");
            exit(0);
        }
        s->top = s->base + s->ssize;
        s->ssize = s->ssize + STACK_INC;
    }
    
    *(s->top++) = e;
    
    return 0;
}

/*********************************************************************
* Pop Stack
**********************************************************************/
int StackPop(SqStack *s, char *e)
{
    if(s->base == s->top)
    {
    	  printf("StackPop():: Stack is Empty!\n");
        return -1;
    }
    
    *e= *(--s->top);
    return 0;
}

/*********************************************************************
* Clear Stack
**********************************************************************/
int StackClear(SqStack *s)
{
    //*s->base = 0;
    memset(s->base, 0, s->ssize);
    
    s->top = s->base;
    
    return 0;
}

/*********************************************************************
* Destory Stack
**********************************************************************/
int StackDestroy(SqStack *s)
{
    free(s->base);
    
    return 0;
} 

/*********************************************************************
* Check Stack Empty
**********************************************************************/
int StackEmpty(SqStack *s)
{
	  if(s->top == s->base)
	  {
	      return 1;
	  }
    return 0;
}

/*********************************************************************
* Check Stack Full
**********************************************************************/
int StackGetTop(SqStack *s)
{
    return ((s->top - s->base) - 1);
}
