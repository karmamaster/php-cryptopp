#ifndef PHP_HASH_MD5_H
#define PHP_HASH_MD5_H

#include "php_hash_interface.h"

CRYPTOPP_HASH_INIT_CLASS_FUNC_HEADER(HashMd5);
PHP_METHOD(PHP_CRYPTOPP_NAMESPACE_HashMd5, __construct);
CRYPTOPP_HASH_REQUIRED_METHODS_HEADER(HashMd5)

#endif /* PHP_HASH_MD5_H */
