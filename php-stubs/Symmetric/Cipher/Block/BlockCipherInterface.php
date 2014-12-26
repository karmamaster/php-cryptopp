<?php

namespace Cryptopp;

interface BlockCipherInterface extends SymmetricCipherInterface
{
    /**
     * Encrypts data
     * @param string $data data to encrypt. Must be aligned to cipher block size.
     * @return string encrypted data
     */
    public function encrypt($data);

    /**
     * Decrypts data
     * @param string $data data to decrypt. Must be aligned to cipher block size.
     * @return string decrypted data
     */
    public function decrypt($data);

    /**
     * Encrypts a data block
     * @param string $block data block
     * @return string encrypted block
     */
    public function encryptBlock($block);

    /**
     * Decrypts a data block
     * @param string $block data block
     * @return string decrypted block
     */
    public function decryptBlock($block);
}
