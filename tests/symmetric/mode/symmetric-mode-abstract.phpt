--TEST--
Symmetric mode abstract
--FILE--
<?php

var_dump(is_a("Cryptopp\SymmetricModeAbstract", "Cryptopp\SymmetricModeInterface", true));

// check that abstract class cannot be extended
class ModeAbstractChild extends Cryptopp\SymmetricModeAbstract{}
$o = new ModeAbstractChild();

try {
    $o->getName();
} catch (Cryptopp\CryptoppException $e) {
    var_dump(get_class($e), $e->getMessage());
}

// check final methods
echo "- final methods:\n";
$reflection = new ReflectionClass("Cryptopp\SymmetricModeAbstract");
$methods    = $reflection->getMethods();

foreach ($methods as $method) {
    if (!$method->isFinal()) {
        continue;
    }

    var_dump($method->getName());
}

?>
--EXPECT--
bool(true)
string(26) "Cryptopp\CryptoppException"
string(65) "Cryptopp\SymmetricModeAbstract cannot be extended by user classes"
- final methods:
string(7) "__sleep"
string(8) "__wakeup"
string(7) "getName"
string(12) "getBlockSize"
string(16) "isValidKeyLength"
string(15) "isValidIvLength"
string(6) "setKey"
string(5) "setIv"
string(6) "getKey"
string(5) "getIv"
string(7) "encrypt"
string(7) "decrypt"
string(7) "restart"
