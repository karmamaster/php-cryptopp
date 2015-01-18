/*
 * This file is part of php-cryptopp.
 *
 * (c) Stephen Berquet <stephen.berquet@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef PHP_CRYPTOPP_EXCEPTION_H
#define PHP_CRYPTOPP_EXCEPTION_H

#include "src/php_cryptopp.h"

void init_class_CryptoppException(TSRMLS_D);
zend_class_entry *getCryptoppException();

#endif /* PHP_CRYPTOPP_EXCEPTION_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 expandtab fdm=marker
 * vim<600: sw=4 ts=4 expandtab
 */
