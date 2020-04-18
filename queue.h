#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <limits.h>

typedef struct queue
{
  int inp;
  int outp;
  int size;
  int *buf;
} Queue;

Queue *new_queue(int n)
{
  int *buff = malloc((n+1)*sizeof(int));
  Queue q = {0,0,n+1,buff};
  Queue *qptr = malloc(sizeof(Queue));
  *qptr = q;
  return qptr;
}

void put(Queue *q, int n)
{
  q -> buf[q -> inp] = n;
  q -> inp = (q -> inp + 1) % q -> size;
}

int get(Queue *q)
{
  int ans = q -> buf[q -> outp];
  q -> outp = (q -> outp + 1) % q -> size;
  return ans;
}

int size(Queue *q)
{
  return (q->inp - q->outp + q -> size) % q -> size;
}
#endif //__QUEUE_H__
