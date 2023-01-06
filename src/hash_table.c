#include "../inc/hash_table.h"
#include <stdio.h>
#include <stdlib.h>

// notice, implicit casts is used at here, we pass a string, but we 
// accept the sum of each char in this string used int, so the result
// is the sum of decimal number of ascii number of each char.
// the return value is what we want to get, we can use it as index in hash table.
// only this we can get the position where we want to access data in the hash table.
// but we should also consider the repeat return value problem.
// it means, it will be possibility that the same returrn value we will get and
// we have pass the different string. then we will handle this problem.
// of course, the different method of hash function will also lead to the different degrees
// of repeated problems. the better hash function will profuce more simple repeatition.

Index hash_ascii(const char *key, int tableSize) 
{
    unsigned int hashValue = 0;

    while (*key != '\0')
    {
        hashValue += *key++;
    }
    return hashValue % tableSize;
}

Index hash_alphabet(const char *key, int tableSize) 
{
    return (key[0] + 27 * key[1] + 729 * key[2]) % tableSize;
}


/**
 * @Author: weiyutao
 * @Date: 2023-01-04 18:07:42
 * @Parameters: 
 * @Return: 
 * @Description: 
*        
* nogtice, we used 32 to instead of 27, because 32 is the power of 2.
* we can use operation to improve the efficient.
* then we can code it based on horner rule.
* k1+27*k2+27^2*k3 = (27*k3+k2)*27+k1
*   x * 32 = x * 2^5 = x<<5
* the first cycle will calculate hashValue<<5 == 0*1 == 0<<5 == 0
*   then add *key++ = k1
* the second cycle will calculate k1<<5
*   then add *key++ = k1*32+k2
* the third cycle will calculate (k1*32+k2)<<5+key3 = key3+32*key2+32^2*key1
* this result is what we want to get.
* so this calculate can code as follow
 */
Index hash(const char *key, int tableSize) 
{
    unsigned int hashValue = 0;
    while (*key != '\0')
    {

        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % tableSize;
}