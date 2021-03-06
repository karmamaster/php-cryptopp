/*
 * This file is part of php-cryptopp.
 *
 * (c) Stephen Berquet <stephen.berquet@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef PHP_RBG_H
#define PHP_RBG_H

#include "src/php_cryptopp.h"

void init_class_RandomByteGenerator(TSRMLS_D);

/* {{{ object creation related stuff */
struct RandomByteGeneratorContainer {
    zend_object std;
    CryptoPP::RandomNumberGenerator *rbg;
};
/* }}} */

/* {{{ methods declarations */
PHP_METHOD(Cryptopp_RandomByteGenerator, __construct);
PHP_METHOD(Cryptopp_RandomByteGenerator, __sleep);
PHP_METHOD(Cryptopp_RandomByteGenerator, __wakeup);
PHP_METHOD(Cryptopp_RandomByteGenerator, generate);
/* }}} */

#endif /* PHP_RBG_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 expandtab fdm=marker
 * vim<600: sw=4 ts=4 expandtab
 */
