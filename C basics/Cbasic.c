#include <stdio.h>

int main() {
  printf("Hello World!"); // Every C statement ends with a semicolon ;
  // return 0 stops the function 
  /* Main always appear in a C program. This is called a function. Any code inside its curly brackets {} will be executed.
  */
  printf("leave line \n horizontal tab \t slash bar \\ \n  leave line \n\n doubleinverted \" \n\n");
  
  //int, float, char, double are different value types. You will have to define them. 

  int integer = 4;
  float floatnum_decimal_7_spaces = 4.1234567;
  double double_decimal_15 = 4.12134478365436;
  char charcaters_in_inverted = 'a';

  printf("integer is %i\nfloat is %f\ndouble is %lf\ncharacter is %c\n" , integer, floatnum_decimal_7_spaces, double_decimal_15, charcaters_in_inverted ); 
  
  /*u need to specify the value type in print statement and it comes in double quotes, u can use sentences and then accordingly 
  you mention what values each type will take respectively after the quotes end. */ 

  //operations 

  float float_sum_int_float = integer + floatnum_decimal_7_spaces;
   printf("sum of float and int is %f\nSum of double and int is %lf\n" , float_sum_int_float , double_decimal_15 + integer);

   // To prevent overwriting of values 

   const int fixatevalue = 15;  

   // now if u try assigning any other value to fixatevalue it wont 

   //lets now do assignment operators
   int x = 10; 
   x += 10; 
   printf("x is 10, x = x + 10 , %i\n" , x);
   x -= 10; 
   printf("x = x - 10 , %i\n" , x);
   x *= 2;
   printf("x = x * 2 , %i\n" , x);
   //similar /= 
   x %= 2;
   printf("x = x mod 2 (remainder) , %i\n" , x);
   x += 100; 
   x &= 2;
   printf("x = x and 10 , %i\n" , x); //answer in 1 0 as true false
   printf("%i\n", x);
   x += 100;
   x |= 2;
   x |= 500;
   x |= 3;
   printf("x = x + 2 , %i\n" , x); //ASKKKK ###############################################
   printf("%i\n", x);
   
   int arrayprint[] = {23,212,34,432,42,32};
   arrayprint[2] = 43;
   printf("%d" , arrayprint[2]);
   int i; 

   for (i =0; i < 6; i ++ ) { 
    printf ("The %i\nth element of array is %i\n" , i , arrayprint [i] );

  }

  // while loop 
  int a = 0;
  while (a < 5) {
    printf("%d\n" , a );
    a ++ ;
  }

//reference operator (&)

  int apple = 23;
  printf("%p" , &apple);

//pointer 
  int mango = 67;
  int* ptr = &mango;

  printf("%p\n" , ptr);
  printf("%d\n" , *ptr); 

  /* usage of *
When used in declaration (int* ptr), it creates a pointer variable.
When not used in declaration, it act as a dereference operator */

  
  //recurssion 

  
     



  return 0;
}













