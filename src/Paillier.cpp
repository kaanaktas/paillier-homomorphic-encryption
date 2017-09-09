//============================================================================
// Name        : PaillierCppProject.cpp
// Author      : kaktas
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <cmath>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <windows.h>
#include "../cryptoUtils/BigIntegerLibrary.hh"

using namespace std;

BigInteger nsquare, n, lambda, g;

BigInteger randomZStarNSquare(int modLength)
{
	BigInteger r;

	do
	{
		r = createRandom(modLength*4);
	}
	while (r >= nsquare || gcd(r, nsquare) != 1);

	return r;
}

BigInteger randomZStarN(int modLength)
{
	BigInteger r;

	do
	{
		r = createRandom(modLength*2);
	}
	while (r >= n || gcd(r, n) != 1);

	return r;
}

void keyGeneration(int bitLength)
{
	srand(time(NULL));

	BigInteger p = findLargePrime(bitLength);
    BigInteger q;

	do
	{
		q = findLargePrime(bitLength);
	}
	while (q.compareTo(p) == 0);

	g = stringToBigInteger("2");

   lambda = ((p-1)*(q-1)) / (gcd(p-1, q-1));
   n = p*q;
   nsquare = n*n;

   cout<<"p prime : "<<p<<endl;
   cout<<"q prime : "<<q<<endl;
   cout<<"g : "<<g<<endl;
   cout<<"lambda : "<<lambda<<endl;
   cout<<"n : "<<n<<endl;
   cout<<"nsquare : "<<nsquare<<endl;

    if(gcd(((modPow(g,lambda, nsquare)-1) / n), n) != 1)
    {
    	cout << "Find another g.";
       return;
    }
}

int main()
{
	keyGeneration(20);

	BigInteger m1 = stringToBigInteger("1231927492188");
	BigInteger m2 = stringToBigInteger("8498728482421");

	BigInteger r = findLargePrime(20);
	BigInteger em1 = Encryption(g, m1, nsquare, n, r);
	BigInteger em2 = Encryption(g, m2, nsquare, n, r);

	BigInteger dm1 = Decryption(g,lambda, em1, nsquare, n);
	BigInteger dm2 = Decryption(g,lambda, em2, nsquare, n);

	cout << "Original value  : " << m1 <<endl<< "Encrypted value : " << em1 <<endl<< "Decrypted value : " << dm1 << '\n';
	cout <<  "===================" << '\n';
	cout << "Original value  : " << m2 <<endl<< "Encrypted value : " << em2 <<endl<< "Decrypted value : " << dm2 << '\n';

	cout <<  "===================" << '\n';

    BigInteger encProduct = (em1*em2) % nsquare;
	BigInteger decProduct = Decryption(g,lambda, encProduct, nsquare, n);

	cout << "Original total  : " << (m1+m2)<<endl << "Encrypted total : " << encProduct <<endl<< "Decrypted total : " << decProduct << '\n';

	return 0;
}
