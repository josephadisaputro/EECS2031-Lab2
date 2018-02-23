#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "identifiers.h"
#include "g_identifiers.h"

#define NUM_TESTS 1000
#define BUFLEN 100
#define TESTBUFLEN 20

#pragma GCC diagnostic ignored "-Wparentheses"

static void f2c(int *tests, int *correct);
static void c2f(int *tests, int *correct);
static void stars(int *tests, int *correct);
static void reverse(int *tests, int *correct);
static int hash(unsigned const char *str);
static int tests_done = 0, tests_passed = 0;

int main(int argc, char **argv)
{
  int tests = 0, correct = 0;
  char buf[BUFLEN];

  srand((unsigned int)time(NULL));

  if(argc != 2) {
    fprintf(stderr,"%s: usage %s number\n", *argv, *argv);
    exit(1);
  }
  argc--; argv++;

  
  f2c(&tests, &correct);
  c2f(&tests, &correct);
  stars(&tests, &correct);
  reverse(&tests, &correct);

  (void) sprintf(buf, "%s%d%d", *argv, tests_passed, tests_done);
  (void) printf("%s %s: tests_done %d tests_passed %d hash %d\n", *argv, 
                (tests == correct) ? "ok" : "incomplete", tests, correct, hash((unsigned char *)buf));
  return(0);
  return 0;
}

static void f2c(int *tests, int *correct)
{
   int i;
   for(i=0;i<NUM_TESTS;i++) {
     float v = (float)rand()/(float)(RAND_MAX) * 200.0f - 100.0f;

     float ans = fahrenheit2celsius(v);
     float g_ans = g_fahrenheit2celsius(v);

     ++*tests;

     if(fabs(ans-g_ans) > 0.01) 
       fprintf(stderr,"f2c test %f ans %f g_ans %f\n", v, ans, g_ans);
     else
       ++*correct;
  }
}

static void c2f(int *tests, int *correct)
{
   int i;
   for(i=0;i<NUM_TESTS;i++) {
     float v = (float)rand()/(float)(RAND_MAX) * 200.0f - 100.0f;

     float ans = celsius2fahrenheit(v);
     float g_ans = g_celsius2fahrenheit(v);

     ++*tests;

     if(fabs(ans-g_ans) > 0.01) 
       fprintf(stderr,"c2f test %f ans %f g_ans %f\n", v, ans, g_ans);
     else
       ++*correct;
  }
}

static void stars(int *tests, int *correct)
{
   int i, j, ans, g_ans;
   char buf[TESTBUFLEN];

   for(i=0;i<NUM_TESTS;i++) {
     int len = rand() % (TESTBUFLEN-1);
     for(j=0;j<len;j++)
       buf[j] = (rand() % 1) ? ' ' : '*';
     buf[len] = '\0';
     ans = count_stars(buf);
     g_ans = g_count_stars(buf);

     ++*tests;

     if(ans != g_ans)
       fprintf(stderr,"stars test '%s' ans %d g_ans %d\n", buf, ans, g_ans);
     else
       ++*correct;
  }
}

static void reverse(int *tests, int *correct)
{
  int i, j;
  int buf[TESTBUFLEN], rev1[TESTBUFLEN], rev2[TESTBUFLEN];

  for(i=0;i<NUM_TESTS;i++) {
    int equal = 1;
    int len = rand() % (TESTBUFLEN-1);
    for(j=0;j<len;j++) 
      rev1[j] = rev2[j] = buf[j] = rand() % 100;

    ++*tests;
    reverse_elements(rev1, len);
    g_reverse_elements(rev2, len);
    for(j=0;equal && j<len;j++)
      equal = rev1[j] == rev2[j];
    if(!equal) {
      fprintf(stderr,"reverse test '");
      for(j=0;j<len;j++)
        fprintf(stderr,"%2d ", buf[j]);
      fprintf(stderr," reversed ");
      for(j=0;j<len;j++)
        fprintf(stderr,"%2d ", rev1[j]);
      fprintf(stderr," g reversed ");
      for(j=0;j<len;j++)
        fprintf(stderr,"%2d ", rev2[j]);
      fprintf(stderr,"\n");
    } else
      ++*correct;
  }
}
    

static int hash(unsigned const char *str)
{
  unsigned long hash = 5381;
  int c;

  /*NOWARN*/
  while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return (int) (hash % 1024);
}

  
