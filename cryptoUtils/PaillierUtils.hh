/*
 * add.h
 *
 *  Created on: 05 Nis 2015
 *      Author: MkkUser
 */

#ifndef ADD_H_
#define ADD_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

BigInteger gcd(BigInteger a, BigInteger b);
BigInteger modPow(BigInteger base, BigInteger exp, BigInteger modulus);
BigInteger modInv(BigInteger a, BigInteger b);
BigInteger Encryption(BigInteger g, BigInteger m, BigInteger nsquare, BigInteger n, BigInteger r);
BigInteger Decryption(BigInteger g, BigInteger lambda, BigInteger c, BigInteger nsquare, BigInteger n);
BigInteger createRandom(const int len);
BigInteger findLargePrime(const int len);

bool Miller(BigInteger p);

#endif /* ADD_H_ */
