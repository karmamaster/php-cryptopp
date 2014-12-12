--TEST--
Hash algorithm: SHA3-224
--SKIPIF--
<?php
if (!class_exists("Cryptopp\HashSha3_224")) {
    echo "skip sha3 not available";
}
?>
--FILE--
<?php

var_dump(is_a("Cryptopp\HashSha3_224", "Cryptopp\HashAbstract", true));

// check that the class can be extended
class HashChild extends Cryptopp\HashSha3_224{}
$o = new HashChild();
var_dump($o->getName());

// check algorithm infos
$o = new Cryptopp\HashSha3_224();
var_dump($o->getName());
var_dump($o->getBlockSize());
var_dump($o->getDigestSize());

// check digest calculation
echo "\n";
var_dump(bin2hex($o->calculateDigest("qwertyuiop")));
var_dump(bin2hex($o->calculateDigest("azerty")));

// check incremental hash
echo "\n";
$o->update("qwerty");
$o->update("uio");
$o->update("p");
var_dump(bin2hex($o->finalize()));

// check that a restart() is not necessary after a call to finalize()
echo "\n";
$o->update("qwerty");
$o->update("uio");
$o->update("p");
var_dump(bin2hex($o->finalize()));

// check restart()
echo "\n";
$o->update("qwerty");
$o->restart();
$o->update("uio");
$o->update("p");
var_dump(bin2hex($o->finalize()));

// check values returned by Cryptopp\Hash for this algorithm
echo "\n";
var_dump(in_array("sha3_224", Cryptopp\Hash::getAlgos()));
var_dump(Cryptopp\Hash::getClassname("sha3_224"));

// sleep
echo "\n";
try {
    serialize($o);
} catch (Cryptopp\CryptoppException $e) {
    echo $e->getMessage() . "\n";
}

// test inheritance
echo "\n";
class Child extends Cryptopp\HashSha3_224{}

$o = new Child();
var_dump($o->getBlockSize());

// test inheritance - parent constructor not called
echo "\n";
class ChildParentConstructorNotCalled extends Cryptopp\HashSha3_224
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
bool(true)
string(8) "sha3_224"
string(8) "sha3_224"
int(0)
int(28)

string(56) "2fa05a669e02a13295588c05a1e91b56d889cf5004f9971789a464bf"
string(56) "39ba050e26e31d0b3e1293a33dfbdecba37e2f0a6e851dd4bed8ccfc"

string(56) "2fa05a669e02a13295588c05a1e91b56d889cf5004f9971789a464bf"

string(56) "2fa05a669e02a13295588c05a1e91b56d889cf5004f9971789a464bf"

string(56) "bcd289219436dabe3b03048bd00913dfe26e86a80a55137f50fc569b"

bool(true)
string(21) "Cryptopp\HashSha3_224"

You cannot serialize or unserialize Cryptopp\HashAbstract instances

int(0)

Cryptopp\HashAbstract cannot be extended by user classes
