#include "helper.h"

int helper_1(int i)
{
  return i+1;
}
int helper_2(int i)
{
  return (i > 10) ? helper_1(i+2) : i-3;
}
