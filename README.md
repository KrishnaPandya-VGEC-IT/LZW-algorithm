# LZW-algorithm
LZW-data compression algorithm(Originally executed in Dev-C++ IDE)

Explanation:
 
    1)This algorithm is based on LZW data compression algorithm.
    2)In some invalid inputs it may cause std:out_of_range(). To understand it in depth, take the inputs from the reference books.
    
Sample Input:
    
     Enter the string:wabba@wabba@wabba@wabba@woo@woo@woo
     
Sample Output:

    -----STRING VECTOR-----

     @       1
     a       2
     b       3
     o       4
     w       5
     wa      6
     ab      7
     bb      8
     ba      9
     a@      10
     @w      11
     wab     12
     bba     13
     a@w     14
     wabb    15
     ba@     16
     @wa     17
     abb     18
     ba@w    19
     wo      20
     oo      21
     o@      22
     @wo     23
     oo@     24
     @woo    25
     
     Encoding sequence->     5       2       3       3       2       1       6       8       10      12      9       11      7       16      5       4       4       11      21      23      4
     
     decoding str:wabba@wabba@wabba@wabba@woo@woo@woo
