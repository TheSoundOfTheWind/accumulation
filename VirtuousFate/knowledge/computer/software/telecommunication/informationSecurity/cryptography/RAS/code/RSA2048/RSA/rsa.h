<<<<<<< HEAD
#include "keys.h"

void rsa_encrypt(DTYPE *cipher, DTYPE cipher_len, DTYPE *msg, DTYPE msg_len, rsa_pk *public_key);

=======
#include "keys.h"

void rsa_encrypt(DTYPE *cipher, DTYPE cipher_len, DTYPE *msg, DTYPE msg_len, rsa_pk *public_key);

>>>>>>> 1d751b2d5d0f314aae5ee85cadda02a076b13d0f
void rsa_decrypt(DTYPE *output, DTYPE output_len, DTYPE *cipher, DTYPE cipher_len, rsa_sk *secret_key);