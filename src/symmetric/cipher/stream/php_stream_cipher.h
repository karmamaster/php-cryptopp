#ifndef PHP_STREAM_CIPHER_H
#define PHP_STREAM_CIPHER_H

#include "../../../php_cryptopp.h"
#include <string>
#include <vector>

void addStreamCipherAlgo(const std::string algoName, const std::string cipherClassname);
std::vector<std::string> getStreamCipherAlgoList();

void init_class_StreamCipher(TSRMLS_D);
PHP_METHOD(Cryptopp_StreamCipher, getAlgos);
PHP_METHOD(Cryptopp_StreamCipher, getClassname);

#endif /* PHP_STREAM_CIPHER_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 expandtab fdm=marker
 * vim<600: sw=4 ts=4 expandtab
 */