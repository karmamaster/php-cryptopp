/*
 * This file is part of php-cryptopp.
 *
 * (c) Stephen Berquet <stephen.berquet@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef PHP_HASH_SHA1_H
#define PHP_HASH_SHA1_H

#include "src/php_cryptopp.h"

void init_class_HashSha1(TSRMLS_D);
PHP_METHOD(Cryptopp_HashSha1, __construct);

#endif /* PHP_HASH_SHA1_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 expandtab fdm=marker
 * vim<600: sw=4 ts=4 expandtab
 */
