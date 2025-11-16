# C++ Windows 95 product key generator
 
## This simple C++ program allows you to generate product keys (OEM and retail) for Windows 95 

1)OEM key:
The logical structure of this key is:

XXXYY-OEM-NNSSSSSS-ZZZZZ

•XXX represents the day and is a random number between 001–366

•YY represents the year and is a random number between 95–99

•“-OEM-” is a const string

•NN consists of two zeros

•SSSSS consists of five random digits whose sum must be divisible by 7, In my algorithm, 
I compute a partial sum of the first four numbers and then add 0 if the remainder of the 
partial sum divided by seven is 0, if it is not, I add 7 minus the remainder of the partial sum

•ZZZZZ consists of five random digits between 00000–99999

2)Retail key:

Its structure is XXX-XXXXXXX

The first 3 numbers must never be equal to 333,444,555,666,777,888, or 999, In my case, to 
simplify, none of the 3 numbers will ever repeat three times 

-the program provides a very simple console user interface 
 
## Algorithm sources

Wikipedia: https://en.wikipedia.org/wiki/Product_key
