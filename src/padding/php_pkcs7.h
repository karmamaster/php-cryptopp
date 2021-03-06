/*
 * This file is part of php-cryptopp.
 *
 * (c) Stephen Berquet <stephen.berquet@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef PHP_PADDING_PKCS7_H
#define PHP_PADDING_PKCS7_H

#include "src/php_cryptopp.h"

extern zend_class_entry *cryptopp_ce_PaddingPkcs7;
void init_class_PaddingPkcs7(TSRMLS_D);

/* {{{ methods declarations */
PHP_METHOD(Cryptopp_PaddingPkcs7, pad);
PHP_METHOD(Cryptopp_PaddingPkcs7, unpad);
PHP_METHOD(Cryptopp_PaddingPkcs7, canPad);
PHP_METHOD(Cryptopp_PaddingPkcs7, canUnpad);
/* }}} */

#endif /* PHP_PADDING_PKCS7_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 expandtab fdm=marker
 * vim<600: sw=4 ts=4 expandtab
 */
