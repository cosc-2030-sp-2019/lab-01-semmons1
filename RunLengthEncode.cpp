//Stefan Emmons
//COSC 2030-01
//Lab 01
//Dr. Hill, or Pedro Marquez
//2-6-2019


// CPP program to implement run length encoding
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line;
	string whitespace(" \t\f\v\n\r");
	vector<string> pix_list;
	int i, count, n;
	ifstream pixf_full;
	pixf_full.open("PixData.txt");
	ofstream pixf_cmpr;
	pixf_cmpr.open("PixCmprs.txt");
	if (pixf_full.is_open()) cout << "Input pixf_full is open. File open success. \n";
	// Read into pix_list.
	i = 0;
	while (getline(pixf_full,line))
	{
		cout << line;
		// 2.  (Explain statement below.)
		//This is a vector function this is used to store data, one line at time from the given "Pixel Test" file.
		//The push back function essentially just pushes back the current set of characters and appends a new set. This repeats until the loop is finished.
		pix_list.push_back(line);
		i = i + 1;
	}
	n = pix_list.size();
	cout << "\nLength of the pix_list vector is " << n << " ; The actual pixel count is represented by 'i', which = " << i << "\n";
	// Go through list, testing whether next pixel is the same.
	for (i = 0; i<n; i++)
	{
		if (pix_list[i + 1] != pix_list[i+1])
			pixf_cmpr << pix_list[i];
		else
		{
			// Pixels same.
			// 1. Write flag character and repeated pixel.  Strip pesky newline at end.
			//A helpful constant for me is the physical word "FLAG". It's easier on my eyes and stands out against the blur
			//of hexidecimal characters.
			pixf_cmpr << "FLAG" << pix_list[i].substr(0, pix_list[i].find_last_not_of(whitespace));
			// 5. (Explain loop below.)
			//The while loop below has the job of counting how many consecutive pixels formats are repeated in the text document before
			//having a new hexidecimal format appear. For example, we can see that the format "ffc0c0c0" appears a lot, 647 times to be exact 
			//and that's just in the beginning of the document. This is a very simple form of RLE encoding. It saves a ton of space by condensing
			//specific formats and patterns. One thing to note is that it would appear the whitespace elimination process chops off
			//any "0" that may appear at the end of these formats. I could not find a way to improve this flagging process, and while it's
			//not a huge deal, it's an important note to make. 
			count = 1;
			while (i < n - 1 && pix_list[i] == pix_list[i + 1])
			{
				count++;
				i++;
			}
			// Different pixel or end of file encountered.
			// Write output to file.
			pixf_cmpr << " " << count << "\n";
		}
	}
	pixf_full.close();
	pixf_cmpr.close();
	system("pause");
	return 0;
}

