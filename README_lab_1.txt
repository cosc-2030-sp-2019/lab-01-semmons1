Stefan Emmons
COSC 2030-01
Lab 01
Dr. Hill, or Pedro Marquez
2-6-2019
Statement of help:
I received a small amount of help from online forums such as "cplusplus.com" whenever I had a question about a specific function, such as the subtract whitespace function.
I also used the textbook for this class, and an academic article written by the University of Alberta for BMP file information. 

As noted in the lab, "...This is a very simple form of RLE encoding. It saves a ton of space by condensing specific formats and patterns. One thing to note is that it would appear the whitespace elimination process chops off
any "0" that may appear at the end of these formats. I could not find a way to improve this flagging process, and while it's not a huge deal, it's an important note to make."
Because of the hexadecimal structure of this Bitmap file, a four-byte zero could be misconstrued as an RGB format. In fact, a four byte zero structure is a format for the black pixel structure. It is a possibility to use this format as a flag, but it is not a good idea. 
A good way to adjust for this "padding" is by using the same "check for a flag 0" function at the end of each hexadecimal structure, and seeing if it is divisible by four. This can be achieved by using an
if statements, and a modulus operator.  
