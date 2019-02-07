# lab-01-semmons1
lab-01-semmons1 created by GitHub Classroom <br />
Stefan Emmons <br />
COSC 2030-01 <br />
Lab 01 <br />
Dr. Hill, or Pedro Marquez <br />
2-6-2019 <br />
UPDATE:
I made sure to heavily comment on just about every process I could in both .cpp files for this lab. If anyone has any questions, please 
look over those comments, or just ask me. I put a fair amount of effort into this lab, so I should be able to explain concepts relatively
clearly. 

Statement of help:
I received a small amount of help from online forums such as "cplusplus.com" whenever I had a question about a specific function, such as the subtract whitespace function.
I also used the textbook for this class, and an academic article written by the University of Alberta for BMP file information. 

As noted in the lab, "...This is a very simple form of RLE encoding. It saves a ton of space by condensing specific formats and patterns. One thing to note is that it would appear the whitespace elimination process chops off
any "0" that may appear at the end of these formats. I could not find a way to improve this flagging process, and while it's not a huge deal, it's an important note to make."
Because of the hexadecimal structure of this Bitmap file, a four-byte zero "padded" structure is possible and fairly common. This padding is usually seen towards the end of a hexadecimal structure.
A good way to adjust for this "padding" is by using the same "check for a flag 0" function at the end of each hexadecimal structure, and seeing if it is divisible by four. This can be achieved by using an
if statements, and a modulus operator.  
