
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BigIntegerLibrary.hh"
#include "CryptGenRandom.h"


char* intToString(int i, char b[])
{
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

BigInteger gcd( BigInteger a, BigInteger b )
{
      BigInteger c;

      while ( a != 0 )
      {
             c = a;
             a = b%a;
             b = c;
      }

      return b;
}

BigInteger modPow(BigInteger base, BigInteger exp, BigInteger modulus)
{
    BigInteger result = 1;

    while(exp >=1)
    {
         if(exp%2 == 1)
         {
             result = (result*base ) % modulus;
         }

         base = (base*base) % modulus;
         exp = exp/2;
    }


    return result;
}

BigInteger modInv(BigInteger a, BigInteger b)
{
        BigInteger b0 = b, t, q;
        BigInteger x0 = 0, x1 = 1;
        if (b == 1)
            return 1;
        while (a > 1) {
            q = a / b;
            t = b, b = a % b, a = t;
            t = x0, x0 = x1 - q * x0, x1 = t;
        }

        if (x1 < 0) x1 += b0;

        return x1;
}

BigInteger Encryption(BigInteger g, BigInteger m, BigInteger nsquare, BigInteger n,  BigInteger r)
{
     return modPow(g, m, nsquare) * modPow(r, n, nsquare);
            // g^m mod n^2		   *   r^n mod n^2
}

BigInteger Decryption(BigInteger g, BigInteger lambda, BigInteger c, BigInteger nsquare, BigInteger n)
{
     BigInteger u = modInv(((modPow(g, lambda, nsquare)-1) / n), n);

     return (((modPow(c, lambda, nsquare)-1) / n)* u) % n;
             // g^m mod n^2		   *   r^n mod n^2
}

BigInteger createRandom(const int keyLength)
{
	const int dwLength = 1;
	unsigned char pbBuffer[dwLength] = {0};

	char* s = (char *) malloc(sizeof(char) * (keyLength + 1));
	s[0] = '\0';

	short int keySize = 0;

	do{
		spc_rand(pbBuffer, dwLength);

		int a = static_cast<int>(pbBuffer[0]);
		int lengthOfInt =  floor(log10(abs(a))) + 1;
		char* s2 = (char *) malloc(sizeof(char) * (lengthOfInt ));
		char* c = intToString(a, s2);
		//cout  << c << endl;
		if((strlen(s)+lengthOfInt) < keyLength)
		{
			strcat(s, s2);
		}
		else
		{
			int x = keyLength - strlen(s);
			memcpy( c, &c[0], x);
			c[x] = '\0';
			//cout  << c << endl;
			strcat(s, c);
		}

		keySize = lengthOfInt + keySize;
	}while(keyLength > keySize);

	cout  <<"sss "<< strlen(s) << " aaa "<< s << endl;

    return stringToBigInteger(s);
}

BigInteger findLargePrime(const int len)
{
	cout<<"================"<<endl;
	BigInteger p = createRandom(len);
	do
	{
		p = p +1;
		//cout<<"prime candidate :" <<p<<endl;
	}while (!Miller(p));

	return p;
}

BigInteger mulmod(BigInteger a, BigInteger b, BigInteger mod)
{
    BigInteger x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

bool Miller(BigInteger p)
{
	int iteration = 5;
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    BigInteger s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
    	BigInteger tt = rand();
        BigInteger a = tt % (p - 1) + 1, temp = s;
        BigInteger mod = modPow(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}
