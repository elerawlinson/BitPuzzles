/* 
 * CS:APP Data Lab
 * 
 * <Elena Rawlinson, erawlinson26>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 9.0.0.  Version 9.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, fourth edition, plus
   Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
   (Amd. 2 was published 2016-05-01,
   see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
       /* utilizes the fact that the negation of (x AND y) is (not x OR not y), and the negation of the negation is the original statement. */ 
       int toret = ~((~x)|(~y));
       return toret; 
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  /*utilizes the fact that the negation of (x OR y) is (not x AND not y) and the negation of the negation is the original statement. */
  int toret = ~((~x)&(~y));
  return toret;
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /*utilizes a very similar strategy to the method above– the fact that the logical negation of (x OR y) is (not x AND not y). */
  int toret = ((~x)&(~y));
  return toret;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* The first step uses the idea that the logical negation of XOR is either (x AND y) OR (not x AND not y). In order to combine these statements with the logic of an or, I used the same strategy 
   * from the above method, bitOr, but I removed the ~ from the bitOr method, because combining the two statements produces the net negation, so I would have just had to do another ~
   * after the or operation, and instead of doing this the two negations essentially cancel eachother out, saving operations.
   */
  int a = x&y;
  int b = ((~x)&(~y));
  int toret = ((~a)&(~b));
  return toret;
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */ 
int evenBits(void) {
  /*
   * used the hex representation of the bitstring '01010101' to construct a 32 bit long string with that pattern by or-ing together the pattern and shifting it
   */
  int toret = (((0x55 | (0x55 <<8)) |(0x55 <<16)) | (0x55 <<24)); 
  return toret; 
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  /*
   *how going from pos-neg works in two's complement
   */
  int toret = ((~1) +1);
  return toret; 
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
  /*
   *took the hex rep of bitstring '00....1' and shifted it over to the right to get '100...00', then utilized the fact that right shifting is sticky to create a string of n-1 1's
   *starting from the 32nd bit (n-1 because there was already 1 bit set to 1)
   *then I had to deal with the corner case of n=0, so I !(X) to get 1 if x=0 and 0 otherwise, and then shifted that all the way to the right and then all the way back, to either get 
   *a bitstring of all 0's (if x != 0) or a bitstring of all 1's (if x==0). 
   *then I & it with the bitstring from step 1, so that if x==0, mask2 would be a bitstring of zeros, and if x !=0, mask2 would just be the same as y
   */
  int y  = (0x1<<31)>> (n+ ((~1)+1)); 
  int startmask = ((!n) << 31) >> 31;
  int mask2 = (~startmask) & y;
  return mask2;  
  
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  /*
   *same logic as the even bits method above, just wrote out the bitstring I wanted and then clumped it into groups of 8 bits to determine hex reprsentation of each section and stitched
   * them together to make the required bitstring
   */
  int toret = (0x49)|(0x92<<8)|(0x24<<16)|(0x49<<24);
  return toret;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  //extract all evens using the mask from the previous even it string problem*/
  int mask = (((0x55 | (0x55 <<8)) |(0x55 <<16)) | (0x55 <<24));
  int xandmask = x&mask;

  //subtract the mask value- which is all evens set to 1, from the result of masking x
  int res = xandmask + (1+(~mask));

  //the result of the subtraction will be 0 if the two numbers are the same, meaning x is all evens =1, and otherwise !=0. ! the result gives 1 for all 1's and 0 for not all one's 
  int toret = !res; 
  return toret;
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
  //collect the odd bits using a mask
  int mask = ~(((0x55 | (0x55 <<8)) |(0x55 <<16)) | (0x55 <<24));
  int xandmask = x&mask;

  //! of the result will be 1 if there are no odd bits set to one, eg if xandmask ==0, otherwise will be 1 if there are any odd bits set to 1. Since
  //we want to return 1 if there are odd bits, we ! it again, to flip the responses and get 1 if there are any odd bits and 0 if there aren't 
  int res = !(!xandmask);
  return res; 
  
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /*takes advantage of the fact that shifting left once multiplies by 2, so shifting left three times is equivalent to multiplying by 8, to get the number of bits the mask needs to be shifted*/
  int moves = n << 3;

  //then collect the byte
  int mask = 0xFF << moves;

  //move it down to the LS bites
  int toret = ((mask&x)>>moves) & 0xFF; 
  return toret;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  //use the method from above to collect both bytes 
  int nmoves = n<<3;
  int mmoves = m<<3;
  int nmask = 0xFF << nmoves;
  int mmask = 0xFF <<mmoves;

  //collect the bytes and shift them both down to the least significant bytes
  int byten = ((nmask&x) >> (nmoves)) &0xFF;
  int bytem = ((mmask&x) >> (mmoves)) &0xFF;

  //zero out the 2 bytes previously occupied by byte n and m 
  int toret = (~(0xFF << (nmoves)) & x);
  toret = toret & (~(0xFF << (mmoves)));

  //OR the resulting x value with byten moved to spot m and byte m moved to spot n
  toret = toret | (byten << (mmoves)) | (bytem << (nmoves)); 
  return toret;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //same logic as minus 1
  int toret = (~x)+1; 
  return toret;
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {

  /*to figure out how many bits to shift the starting mask right, (eg add zeros from most sig bit-highbit), we want to subtract the highbit vaule fromt 31, but since '-' isn't an allowed operation, I used the same logic as the negate method above to make 0x1F, 31, -31, and then added this to high bit */
  int highshift = ((~highbit)+1) + 0x1F;

  /*to create a bit string with the correct highbit starting point and the rest of the string = 1's, I first started with a bitstring 01..11111 (created by shifting 1 31 bits and negating it) I did this instead of ~0 because right shifting is done arithmatically, which means shifting right would result in 1's being added to the most significant position, instead of zeros as I wanted. Then I shifted this starting mask right by highshift. Then, in order to account for the extra starting 0, I or'd that bitstring with 0x1 shifted by 31-highshift, essentially setting the least significant bit which had been set to 0 back to 1. I originally just shifted right by highshift-1, but this caused issues when highshift = 0 */

  int highmask = ((~(0x1<<31)) >> (highshift) | (0x1<< ( 31 + ( ( ~highshift ) +1 ) )));

  /*then to make the low mask, I simply made a mask of 111..111 by negating 0 and shifted it left by lowbits- thus setting all of the lowest bits up to lowbit to zero*/
  int lowmask = ((~0) << lowbit);

  /*I & the two masks so that the only remaining 1's in the bitstring would be between the highbit and lowbit bounds, resulting in the desired bit string*/
  int toret = highmask & lowmask;
  return toret; 
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*
   *I started by creating a mask based on x's value- if x = 0, then the startmask is all 1's, if x !=0 then the start mask is all 0s
   */
  int startmask = ((!x) << 31) >> 31;

  //then and the startmask with whatever value you want to return if x = 0 (it will be copied since if x =0, start mask is all 1's
  int mask1 = (startmask & z);

  //negate start mask and it with y- this is the value you want to return if x!=0
  int mask2 = (~startmask) & y;

  //or the two masks, one of them will be all 0's and one will contain the value you want to return 
  int last = mask1 | mask2; 
  return last;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {

  /* uses methodology from getByte to collect the top n and lower n bits, then uses similar logic to the swap byte method to move the upper n bits to the LSB positions and vice versa
   */

  //make mask to collect lowest n bits, then chop them off of x
  int mask1 = (~((~0)<<n)) & x; 
  int step1 = x >> n; 

  //make mask to collect upper n-1 bits 
  int mask2a = (0x1<<31);
  int mask2b = (mask2a >> (n + (1+(~1))));

  //invert mask to collect upper n-1 bits, so now it collects lower 32-n-1 bits
  int mask2c = ~mask2b;
  //collect lower n bits 
  int step2 = step1 & mask2c;
  int step3 = (mask1<< 32 + (~(n)+1)); /*move collected lower bits to the top n bits*/
  int toret = step2 | step3;
  /*zero case*/
  int startmask = ((!n) << 31) >> 31;
  int zerom1 = (startmask & x);
  int zerom2 = (~startmask) & toret;
  int last = zerom1 |zerom2;
  return last; 
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  /*collect sign bits*/
  int signmask = 0x1<<31;
  int xsign = x&signmask;
  int ysign = y&signmask;
  //two cases where subtraction gives result that doesnt make sense: neg-pos = pos or pos - neg = neg 
  int ressign = (x+ (1+(~y)))&signmask;
  int toret = !((xsign ^ ysign) & (x^ressign)); 
  return toret; 
  
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /*masks sign bit, then uses the code from conditional to return x if the sign bit is 0 (alr pos) and -x if the sign bit is 1*/
  int signbit = x>>31;
  int startmask = ((!signbit) << 31) >> 31;
  int mask1 = (startmask & x);
  int mask2 = (~startmask) & (1+(~x));
  int last = mask1 | mask2;
  return last;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /*brute force method- masks off each bit individually and adds it to the sum if it's a 1*/
  int mask = 1;
  int count = (x&1)+((x>>1)&1)+((x>>2)&1)+((x>>3)&1)+((x>>4)&1)+((x>>5)&1)+((x>>6)&1)+((x>>7)&1);/*bits 0-7*/
  int count2 = count + ((x>>8)&1)+ ((x>>9)&1) + ((x>>10)&1)+ ((x>>11)&1)+ ((x>>12)&1)+ ((x>>13)&1)+ ((x>>14)&1)+ ((x>>15)&1)+ ((x>>16)&1); /*bits 8-16*/
  int count3 = count2 + ((x>>17)&1)+((x>>18)&1)+((x>>19)&1)+((x>>20)&1)+((x>>21)&1)+((x>>22)&1)+((x>>23)&1)+((x>>24)&1)+((x>>25)&1);
  int count4 = count3 + ((x>>26)&1)+((x>>27)&1)+((x>>28)&1)+((x>>29)&1)+((x>>30)&1)+((x>>31)&1);
  return count4;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {

  /*using bitcount method above to get the literal number of 1's*/
  int mask = 1;
  int count = (x&1)+((x>>1)&1)+((x>>2)&1)+((x>>3)&1)+((x>>4)&1)+((x>>5)&1)+((x>>6)&1)+((x>>7)&1);/*bits 0-7*/
  int count2 = count + ((x>>8)&1)+ ((x>>9)&1) + ((x>>10)&1)+ ((x>>11)&1)+ ((x>>12)&1)+ ((x>>13)&1)+ ((x>>14)&1)+ ((x>>15)&1)+ ((x>>16)&1); /*bits 8-16*/
  int count3 = count2 + ((x>>17)&1)+((x>>18)&1)+((x>>19)&1)+((x>>20)&1)+((x>>21)&1)+((x>>22)&1)+((x>>23)&1)+((x>>24)&1)+((x>>25)&1);
  int count4 = count3 + ((x>>26)&1)+((x>>27)&1)+((x>>28)&1)+((x>>29)&1)+((x>>30)&1)+((x>>31)&1); 


  int numzeros = (32 + (1+(~count4)));  

  /*figure out if the number of 0's is even or odd by dividing the number of 0's by 2 via leftshift once, then adding this halved value to itself, subtracting this sum from the original value
   *since the division rounds down, if the number is odd, the original number minus the sum of the two halves will be != 0, and then uses ! to return 0 if the result of this calulation is !=0 and 1 if i
   *is (if there are an even number of 0's
   */
  
  int test1 = numzeros>>1;
  int test2 = test1+test1;
  int test3 = !(!(numzeros + (1+(~test2))));

  return test3; 
  
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {

  //get all the signs- of x, y, and the resulting sum 
  int signmask = 0x1<<31;
  int xsign = ((x>>31) & 0x1);
  int ysign = ((y>>31) & 0x1);
  int ressign = ((x+y)>>31) & 0x1;

  /*assigning alt return value- since there are three possible values to return, pos overflow, neg overflow, or x+y, I used conditional twice here
   *the first time I used it was below, to assign the alternate return value to one of the overflow constants based on the result's sign  
   */
  int startmaskalt = ((!ressign) << 31) >> 31;
  int mask1a = (startmaskalt & (signmask));
  int mask2a = (~startmaskalt) & (~(signmask));
  int altret = mask1a | mask2a;

  /*assigning x+y or overflow return value*/
  int test1 = (!(xsign^ysign)); 
  int test2 = (xsign^ressign);
  int test3 = test1 &test2; 
  int startmask = ((!test3) << 31) >> 31;
  int mask1 = (startmask & (x+y));
  int mask2 = (~startmask) & (altret);
  int last = mask1 | mask2;

  return last; 
}

/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  /*collected the sign, then either returned negated value based on negation method of two's complement or returned the value as is, used conditional logic*/
  int sign = ((0x1<<31) &x);
  int zeromask = (~(0x1<<31)) & x;
  int negver = (~zeromask)+1;
  int startmask = ((!sign) << 31) >> 31;
  int mask1 = (startmask & x);
  int mask2 = (~startmask) & negver;
  int last = mask1 | mask2;
  return last; 
}
