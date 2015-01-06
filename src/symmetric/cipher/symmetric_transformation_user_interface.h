#ifndef PHP_SYMMETRIC_TRANSFORMATION_USER_INTERFACE_H
#define PHP_SYMMETRIC_TRANSFORMATION_USER_INTERFACE_H

#include "../../php_cryptopp.h"

class SymmetricTransformationUserInterface
{
public:
    virtual bool IsValidIvLength(size_t n) =0;
};

#endif /* PHP_SYMMETRIC_TRANSFORMATION_USER_INTERFACE_H */
