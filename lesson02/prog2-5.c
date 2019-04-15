/*********************************************
  prog2-6.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <assert.h>

int gcd(int p, int q);

int gcd(int p, int q)
{
  int tmp,rest;
  if (p < q){
    tmp = q;
    q = p;
    p  = tmp;
  }
  if(q == 0){
    return p;
  }else{
    rest = p % q;
    return gcd(q,rest);
  }
}

/*=============================================*/

void test1()
{
  assert(gcd(54,60) == 6);
  
  printf("Success: %s\n", __func__);
}
int main()
{
   test1();
  return 0;
}
