#include <math.h>
#include <stdio.h>




int min=1, max=1000;
  
int inRange(int x)
{
  return (min<=x && x<=max);
}

/* dumbest possible way to compute this, almost. */
int isPrime(int x)
{
  int i;
  int limit;
  if (x<=3) return 1;
  limit = (int)sqrt((double)x);
  
  for(i=2; i<=limit; i++) {
    if ((x%i)==0)
      return 0;
  }
  return 1;
}

int isAlwaysSumOfComposite(int s)
{
  int a;
  int limit = s/2;

  for(a=min; a<=limit; a++) {
    if (isPrime(a) && isPrime(s-a)) {
      return 0;
    }
  }
  return 1;
}
/* Mr. S:  I knew you didn't know */
/* Given s, for all pairs (a,b), a+b=s, 2 <= a,b <= 99,
  true if at least one of a or b is composite */
int satisfiesRule2(int s)
{
  return isAlwaysSumOfComposite(s);
}

/* Mr. P:  I know! */
/* Given p, for all pairs (a,b), ab=p, 2 <= a,b <= 99, 
  true if exactly one pair satisfies rule 2 */
int satisfiesRule3(int p)
{
  int i;
  int limit;
  int winner=0;
  
  limit = (int)sqrt((double)p);
  for(i=min; i<=limit; i++) {
    if (p%i == 0) {
      int j = p/i;
      if (!inRange(j))
  continue;
      if (satisfiesRule2(i+j)) {
  if (winner)    return 0;
  winner=1;
      }
    }
  }
  return winner;
}
/* Mr. S: I know! */
/* Given s, for all pairs (a,b), a+b=s, 2 <= a,b <= 99,
  true if exactly one pair satisfies rules 2 and 3 */ 

int satisfiesRule4(int s)
{
  int a,b;
  int limit = s/2;
  int winner=0;

  if (!satisfiesRule2(s)) /* this is really necessary --
           some false answers */
    return 0;     /* are produced without it. */

  for(a=min; a<=limit; a++) {
    b = s-a;
    if (satisfiesRule3(a*b)) {
      if (winner)  return 0;
      winner=a;
    }
  }
  return winner;
}
int main() {
  int a,b;
  int s, p;

  for(s=2*min; s<= 2*max; s++) {
    if ((a=satisfiesRule4(s)) != 0)
      printf("winning sum %d (%d + %d)\n", s, a,s-a);
  }
  return 0;
}