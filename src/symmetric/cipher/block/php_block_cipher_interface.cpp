/*
 * This file is part of php-cryptopp.
 *
 * (c) Stephen Berquet <stephen.berquet@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include "src/php_cryptopp.h"
#include "src/symmetric/cipher/php_symmetric_cipher_interface.h"
#include "php_block_cipher_interface.h"

/* {{{ PHP interface declaration */
zend_class_entry *cryptopp_ce_BlockCipherInterface;

static zend_function_entry cryptopp_methods_BlockCipherInterface[] = {
    PHP_ABSTRACT_ME(Cryptopp_BlockCipherInterface, encryptBlock, arginfo_BlockCipherInterface_encryptBlock)
    PHP_ABSTRACT_ME(Cryptopp_BlockCipherInterface, decryptBlock, arginfo_BlockCipherInterface_decryptBlock)
    PHP_ABSTRACT_ME(Cryptopp_BlockCipherInterface, encrypt, arginfo_BlockCipherInterface_encrypt)
    PHP_ABSTRACT_ME(Cryptopp_BlockCipherInterface, decrypt, arginfo_BlockCipherInterface_decrypt)
    PHP_FE_END
};

void init_interface_BlockCipherInterface(TSRMLS_D) {
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(ce, "Cryptopp", "BlockCipherInterface", cryptopp_methods_BlockCipherInterface);
    cryptopp_ce_BlockCipherInterface = zend_register_internal_interface(&ce TSRMLS_CC);

    zend_class_implements(cryptopp_ce_BlockCipherInterface TSRMLS_CC, 1, cryptopp_ce_SymmetricCipherInterface);
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 expandtab fdm=marker
 * vim<600: sw=4 ts=4 expandtab
 */
