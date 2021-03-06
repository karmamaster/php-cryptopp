--TEST--
Hash algorithm: SHA3-384 (errors)
--SKIPIF--
<?php
if (!class_exists("Cryptopp\HashSha3_384")) {
    echo "skip sha3 not available";
}
?>
--FILE--
<?php

$o = new Cryptopp\HashSha3_384();

// sleep
echo "- sleep:\n";
try {
    serialize($o);
} catch (Cryptopp\CryptoppException $e) {
    echo $e->getMessage() . "\n";
}

// bad arguments
echo "- bad arguments:\n";
var_dump(@$o->calculateDigest(array()));
echo "$php_errormsg\n";
var_dump(@$o->update(array()));
echo "$php_errormsg\n";

// test inheritance
echo "- inheritance:\n";
class Child extends Cryptopp\HashSha3_384{}

$o = new Child();
var_dump($o->getBlockSize());

// test inheritance - parent constructor not called
echo "- inheritance (parent constructor not called):\n";
class ChildParentConstructorNotCalled extends Cryptopp\HashSha3_384
{
    public function __construct(){}
}

$o = new ChildParentConstructorNotCalled();

try {
    $o->getBlockSize();
} catch (Cryptopp\CryptoppException $e) {
    echo $e->getMessage() . "\n";
}

?>
--EXPECT--
- sleep:
You cannot serialize or unserialize Cryptopp\HashAbstract instances
- bad arguments:
NULL
Cryptopp\HashAbstract::calculateDigest() expects parameter 1 to be string, array given
NULL
Cryptopp\HashAbstract::update() expects parameter 1 to be string, array given
- inheritance:
int(136)
- inheritance (parent constructor not called):
Cryptopp\HashAbstract cannot be extended by user classes
