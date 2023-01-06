/**********************************************************************
 * Copyright (C) 2023. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2023-01-04 13:30:16
 * @Last Modified by: weiyutao
 * @Last Modified time: 2023-01-04 13:30:16
 * @Description: Here we will learn hash table, what is samed to the binary search tree,
 * but it does not support to return any sort information about data, it just
 * support insert, delete and find, it does not support return some sort information, 
 * just like findMin, findMax and so on.
 * the ideal status about hash table structure is just a fixed size array, that
 * dedicated to store the keyword. because a hash table has the fixed size, so what we need to
 * do is to define a function that mapped each keyword to a number in the range from 0 to size-1.
 * this function can be also named hash function. this function should ensure different
 * keyword can map to a different value.
 * 
 * because the character is what we want to store used hash table most of the time.
 * so we consider to define the function used the ascii table. you can get the ascii code of each char.
 * the max decimal number that char for ascii code is 127. so we can define a simple hash function used it.
 * 1 byte has 8 bit, so the max dicimal number for 1 byte string is 127*8=1016.
 * 1 bit, you can also consider the char, the max decimal number of ascii code is 127.
 * so the range is from 0 to 1016 if you used the method. the condition that we used is 
 * assuming that the size of string you want to store is less that 1 byte.
 * then the address or the number that tha hash table will store is 
 * the sum of all ascii number % size. the size is the size of hash table.
 * it is generally take a prime number, just like 10007, why used prime number?
 * because the feature of prime number is it just can just be divisible by 1 and itself.
 * this feature can ensure the return value is not zero after taking over.
 * but this function can not ensure the results of the uniform distribution after taking over.
 * so this function is simple and inaccurate.
 * 
 * 
 * 
 * another method to define this function used 26 english alphabet.
 * the numebr of 26 english alphabet add one space is 27. assume that the string
 * we want to store has 2 char at least and end with null. then 
 * we just consider the first two characters.
 * 27^2=729   27^3 = 729   27^0 = 1
 * then we will use bit right to calculate the index.
 * but we have to say that this method will get a uneven distribution.
 * because 26^3 = 17576, it means we will get 17576 numbers combinations.
 * but the different conbination string made up of three english character just has 2851 numbers.
 * if we have a large hash table size, just like 10007, 2851 / 10007 = 0.28
 * it means the distribution will be 28%, so it will be uneven distribution.
 * 
 * 
 * 
 * 
 * then we will consider a better method. it will get the better distribution.
 * this method also used ascii decimal number. but the rule is different from the first method.
 * the first method is simple sum the ascii decimal numebr of each char in your string.
 * this method rule is sum the ascii decimal number * 32^i
 * and it is also add each char, but it is the highest bit multiplied by the min bit right.
 * the i is range from 0 to keySize-1. just like, it is (key[keySize - 1] * 32^0 + key[keySize - 2] * 32^1 + ...) % tableSize.
 * this method is the best method to define a hash function so far. because it has
 * the better distribution. the better distribution will result to
 * the less repeatition.
 * 
 * 
 * then we will learn how to reduce the repeatation rate.
 * the first method is separate chaining. this method will
 * store the same value that different string has in a table. then
 * the complete query method is find the table used hash function first.
 * then find the string what you want to query in the table. the method
 * find the string from one table is traverse. the insert method, you should
 * insert the string at the start or end of the table. if insert the repeated string,
 * we usually add a table fields, if add one repeat string, this fields++;
 * the table at here is not array table, it is listNode. then we will implement this method.
 * because it used listNode, so we will define the struct, but we can also chech if we have defined it
 * before. if not, we can defined it at here.
***********************************************************************/
#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

typedef unsigned int Index;
Index hash_ascii(const char *key, int tableSize);
Index hash_alphabet(const char *key, int tableSize);
Index hash(const char *key, int tableSize);


#endif