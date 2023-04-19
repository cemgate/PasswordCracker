# Password Cracking Program
## Project Description
Polish description -> [Link](https://kcir.pwr.edu.pl/~witold/opsys/opsysA_23.html)

The task was to write a multithreaded program for password cracking using a dictionary attack with the MD5 cryptographic algorithm.

## Prerequisites
To run the program on Windows, the MD5 library from OpenSSL -> [Link how to instal OpenSSL](https://www.youtube.com/watch?v=jSkQ27sTto0&ab_channel=TechDeepDive).

## Program Operation
The program reads a file with a dictionary of passwords and iterates through all the passwords in the file. For each password, the program calculates the MD5 hash value and compares it with the hash value of the password we want to crack. If the values are identical, the program displays the cracked password and continues to crack other passwords. If the program compares all the passwords with the calculated MD5 hash, it reads the next word from the dictionary and continues the same process. The program also includes multiple threads that read the same word but create different combinations, such as word + digit, digit + word, word + word, and so on.

## How to Use the Program
To use the program, first make sure the MD5 library is installed. Then, compile the program and run it in the command line, specifying the file with the passwords to crack as an input.



