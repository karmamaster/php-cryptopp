import os

def getConfig(cryptoppDir):
    config = {}

    config["enabled"]               = True
    config["srcFileList"]           = ["symmetric/cipher/authenticated/php_authenticated_symmetric_cipher_abstract.cpp"]
    config["headerFileList"]        = ["symmetric/cipher/authenticated/php_authenticated_symmetric_cipher_abstract.h"]
    config["phpMinitStatements"]    = ["init_class_AuthenticatedSymmetricCipherAbstract(TSRMLS_C);"]

    return config
