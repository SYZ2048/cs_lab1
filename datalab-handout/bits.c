/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 *Yan xinrui 19307130359
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
     check the legality of your solutions.
     check the legality of your solutions.
     check the legality of your solutions.
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 *1  bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
      	return ~(~(~x&y))&(~(x&~y));//求~x&y得到x为0 y为1的位，x&~y得到x为1，y为0的位，这些位被记为1，其余位为0
	//分别取反后，其余位为1，异位为0，&操作后进行～操作，得到结果
}

/* 
 *2  tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
	x=0x1;
	x<<31;
  return x;//1，向左位移31位得到Tmin
}


//2
/*
 *3  isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) //若x为最大补码，即为0111...111
{
	int m,n;
	m=0x1;
	n=m<<31;//n为100...000
  return !(x&n)&&(!(~x<<1));//先验证符号位为0，再验证后面所有位为0
}
/* 
 *4  allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int m=0x55;
	m=m<<8+m;
	m=m<<8+m;
	m=m<<8+m;//使得m=0101...0101
		
	return !(~(m|x));//若x有奇数位为0，则m|x就不全为1，~(m|x)就不为0
}

/* 
 *5  negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) 
{
	x=~x+1;//补码规则
  return x;
}

//3
/* 
 *6  isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int m=0x30,n=0x39;
	m=~m+1;//m=-30
	n=~n+1;//n=-39
  return !((x+m)>>31)&&(x+n)>>31;//若x满足，则x-30>=0,且x-39<=0
}
/* 
 *7  conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) 
{
	return (~!!x+1)&y|(~!x+1)&z;//若x=0，~!!x+1=0x0,(~!!x+1)&y=0，进入下一个部分，~!x+1=0xffffffff,输出z
  				//若x!=0,~!!x+1=0xffffffff,&y后=y，进入下一部分，~!x+1=0
}

/* 
 *8  isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) 
{
	x=~x+1;//x=-x;
	int sign=(x+y)>>31;//y-x's sign
	//if x<=y,then y-x>=0,sign=0;
	//else sign=1
  return !sign;
}

//4
/* 
 *9  logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) 
{
	int neg_x=~x+1;
	int result=(x|neg_x)>>31;  //only when x=0, -x=-0 sign(x)=sign(-x)=0

  return result^0x1;
}

/*10  howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
	//若x是正数，找第一个1，若x是负数，取反后，找第一个1;
	//依次检索x的前16、8、4、2、1位，每逢全0就移动后位到最前；
	int x_reverse=x^(x>>31);//若x是正数，x>>31为全0，仍得到x；若x是负数，x>>31为全1，得到~x
	int bits_16=(!!(x_reverse&(0xff<<24+0xff<<16))<<4;//若x前16位全0，bits_16为0,若x前16位非全0，bits_16=16
	int bits_8=(!!(x_reverse<<bits_16)&(0xff<<24))<<3;//若x前16位全为0，移动16位，否则不动。其他思路同上
	int bits_4=(!!(x_reverse<<bits_8)&(0xf<<28))<<2;
	int bits_2=(!!(x_reverse<<bits_4)&(0xc<<30)<<1;
	int bits_1=(!!(x_reverse<<bits_2)&(0x1<<31);
	int bits=bits_16+bits_8+bits_4+bits_2+bits_1;
	
  return bits|1;
}
//float
/* 
 *11  floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of  a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
	unsigned int sign=uf&0x8000000;//符号位
	unsigned int exp=uf&0x7f800000;//阶码
	unsigned int frac=uf&0x7fffff;//f
	if(exp==0)//非规格数，把frac乘二
		frac=frac<<1;
	else exp=exp+1;//规格数就exp+1
		if(exp==0x7f800000) return 0x80000000u;//NaN和无穷就输出0x8000000
	return sign+exp+frac;
}

/* 
 *12  floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	unsigned int sign=uf>>31;
 	unsigned int exp=uf>>23&0xff;
	unsigned int frac=uf&0x7fffff;
	int bias=127;
	unsigned int E=exp-bias;
	int result;
	if(exp==0)//非规格数
		result=frac；
	if(exp==0xff)//NaN或无穷
                return 0x80000000u;
	
	if(exp!=0&exp!=0xff)//规格数
	{	if(E>31) return 0x80000000;
		if(E<0) return 0;
		else	result=(1+frac)<<(exp-bias);

	if(sign) return ~result+1;
                else return result;
}
/* 
 *13  floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	if(x<0) return 0;//值<=1/2,向偶数舍入得到0
	if(x>127) return 0x80000000u;//超出exp表达范围
	else return (x+127)<<23;//f=0,exp=E+bias=x+127
}

