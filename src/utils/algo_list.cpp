/*
 * This file is part of php-cryptopp.
 *
 * (c) Stephen Berquet <stephen.berquet@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include "src/php_cryptopp.h"
#include "algo_list.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/* {{{ AlgoList::addAlgo
   adds an algorithm */
void AlgoList::addAlgo(const std::string algoName, const std::string hashClassname)
{
    algoList.push_back(algoName);
    classList.push_back(hashClassname);
}
/* }}} */

/* {{{ AlgoList::getAlgoList
   returns algorithm list */
vector<string> AlgoList::getAlgoList()
{
    vector<string> _algos(algoList);
    sort(_algos.begin(), _algos.end());
    return _algos;
}

void AlgoList::getAlgoList(zval *returnValue)
{
    array_init(returnValue);
    vector<string> _algos = getAlgoList();

    for (vector<string>::iterator it = _algos.begin(); it != _algos.end(); ++it) {
        add_next_index_string(returnValue, it->c_str(), it->length());
    }
}
/* }}} */

/* {{{ AlgoList::getAlgoClass
   returns the class name of an algorithm */
string AlgoList::getAlgoClass(const string &algoName)
{
    vector<string>::iterator iterator = find(algoList.begin(), algoList.end(), algoName);

    if (iterator == algoList.end()) {
        // hash algorithm not found
        return "";
    } else {
        // hash algorithm found
        // return corresponding hash classname
        int pos = iterator - algoList.begin();
        return classList[pos];
    }
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
