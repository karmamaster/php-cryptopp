import os

def getConfig(cryptoppDir):
    config = {}

    config["enabled"]               = True
    config["srcFileList"]           = ["symmetric/cipher/block/php_block_cipher_interface.cpp"]
    config["headerFileList"]        = ["symmetric/cipher/block/php_block_cipher_interface.h"]
    config["phpMinitStatements"]    = ["init_interface_BlockCipherInterface(TSRMLS_C);"]

    return config
