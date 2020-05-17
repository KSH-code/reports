// 최적화, 가독성은 고려 안함

#include <iostream>
#include <vector>

using namespace std;

int count1Bit(unsigned int n)
{
  int c = 0;
  for (int i = 0; i < 32; i++)
  {
    if ((n & (1 << i)) > 0)
      c++;
  }
  return c;
}

int main(void)
{
  int testCases;
  cin >> testCases;
  while (testCases-- > 0)
  {
    unsigned int k, n;
    cin >> k >> n;
    if (k == 0)
    {
      unsigned t = 0;
      int count = 0;
      for (int i = 0; i < 31; i++)
      {

        if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15)
          continue;

        if ((n & (1 << count)) > 0)
        {
          t |= 1 << i;
        }
        count++;
      }
      unsigned int p[] = {t & 0b01010101010101010101010101010100,
                          t & 0b01100110011001100110011001100100,
                          t & 0b01111000011110000111100001110000,
                          t & 0b01111111100000000111111100000000,
                          t & 0b01111111111111110000000000000000};
      unsigned int pb = 0;
      count = 0;
      for (int i = 0; i < 31; i++)
      {
        if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15)
        {
          if ((i == 0 && count1Bit(p[0]) % 2 != 0) || (i == 1 && count1Bit(p[1]) % 2 != 0) || (i == 3 && count1Bit(p[2]) % 2 != 0) || (i == 7 && count1Bit(p[3]) % 2 != 0) || (i == 15 && count1Bit(p[4]) % 2 != 0))
          {
            pb |= 1 << i;
          }
          continue;
        }
        if ((n & (1 << count)) > 0)
        {
          pb |= 1 << i;
        }
        count++;
      }
      printf("%d\n", pb);
    }
    else
    {
      unsigned int p[] = {n & 0b01010101010101010101010101010100,
                          n & 0b01100110011001100110011001100100,
                          n & 0b01111000011110000111100001110000,
                          n & 0b01111111100000000111111100000000,
                          n & 0b01111111111111110000000000000000};
      int pb = 0;
      if (count1Bit(p[0]) % 2 == 0 && (n & 0b1) > 0 || count1Bit(p[0]) % 2 == 1 && (n & 0b1) == 0)
      {
        pb += 1;
      }
      if (count1Bit(p[1]) % 2 == 0 && (n & 0b10) > 0 || count1Bit(p[1]) % 2 == 1 && (n & 0b10) == 0)
      {
        pb += 2;
      }
      if (count1Bit(p[2]) % 2 == 0 && (n & 0b1000) > 0 || count1Bit(p[2]) % 2 == 1 && (n & 0b1000) == 0)
      {
        pb += 4;
      }
      if (count1Bit(p[3]) % 2 == 0 && (n & 0b10000000) > 0 || count1Bit(p[3]) % 2 == 1 && (n & 0b10000000) == 0)
      {
        pb += 8;
      }
      if (count1Bit(p[4]) % 2 == 0 && (n & 0b1000000000000000) > 0 || count1Bit(p[4]) % 2 == 1 && (n & 0b1000000000000000) == 0)
      {
        pb += 16;
      }
      if (count1Bit(pb) > 1)
      {
        n |= 1 << pb - 1;
      }
      unsigned int result = 0;
      int count = 0;
      for (int i = 0; i < 31; i++)
      {
        if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15)
          continue;
        if ((n & (1 << i)) > 0)
          result |= 1 << count;
        count++;
      }
      printf("%d\n", result);
    }
  }
  return 0;
}
