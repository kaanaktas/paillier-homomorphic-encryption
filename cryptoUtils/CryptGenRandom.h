/*
 * CryptGenRandom.h
 *
 */

#ifndef CRYPTGENRANDOM_H_
#define CRYPTGENRANDOM_H_


void spc_rand_init(void);
unsigned char *spc_rand(unsigned char *pbBuffer, size_t cbBuffer);

#endif /* CRYPTGENRANDOM_H_ */
