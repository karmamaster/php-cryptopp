/*
 * This file is part of php-cryptopp.
 *
 * (c) Stephen Berquet <stephen.berquet@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef PHP_AUTHENTICATED_SYMMETRIC_CIPHER_GCM_H
#define PHP_AUTHENTICATED_SYMMETRIC_CIPHER_GCM_H

#include "src/php_cryptopp.h"
#include <gcm.h>

void init_class_AuthenticatedSymmetricCipherGcm(TSRMLS_D);
PHP_METHOD(Cryptopp_AuthenticatedSymmetricCipherGcm, __construct);

/* {{{ fork of CryptoPP::GCM that take a cipher as parameter instead of a template parameter */
class GCM
{
public:
    /* {{{ base class */
    class Base : public CryptoPP::GCM_Base
    {
    public:
        ~Base();
        static std::string StaticAlgorithmName() {return std::string("GCM");}

    protected:
        Base(CryptoPP::BlockCipher *cipher, bool cipherMustBeDestructed);

    private:
        CryptoPP::GCM_TablesOption GetTablesOption() const {return CryptoPP::GCM_2K_Tables;}
        CryptoPP::BlockCipher & AccessBlockCipher() {return *m_cipher;}

        bool m_cipherMustBeDestructed;
        CryptoPP::BlockCipher *m_cipher;
    };
    /* }}} */

    /* {{{ encryption class */
    class Encryption : public Base
    {
    public:
        Encryption(CryptoPP::BlockCipher *cipher, bool cipherMustBeDestructed) : Base(cipher, cipherMustBeDestructed){};
        bool IsForwardTransformation() const {return true;}
    };
    /* }}} */

    /* {{{ decryption class */
    class Decryption : public Base
    {
    public:
        Decryption(CryptoPP::BlockCipher *cipher, bool cipherMustBeDestructed) : Base(cipher, cipherMustBeDestructed){};
        bool IsForwardTransformation() const {return false;}
    };
    /* }}} */
};
/* }}} */

#endif /* PHP_AUTHENTICATED_SYMMETRIC_CIPHER_GCM_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 expandtab fdm=marker
 * vim<600: sw=4 ts=4 expandtab
 */
