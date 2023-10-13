// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:                CS213-2023-20220252-20220051-20220024-A1-Part1.cpp
// Last Modification Date:      10/10/2023
// Author1 and ID and Group:    Kerolos Bedier Soliman - 20220252 - N/A
// Author2 and ID and Group:    Adham salah ezzat  - 20220051 - N/A
// Author3 and ID and Group:    Ahmed Atef Mohamed - 20220024 - N/A
// Teaching Assistant:          N/A
// Purpose:                     Assignment 1 Image Processor

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void main_menu();
void loadImage ();
void saveImage ();
void repeat_or_finish(); 


// THE FUNCTIONS TO DO TO THE PHOTO 
 


int main() {
	loadImage();
	main_menu();
	saveImage();	
    return 0;
}


void main_menu() {     // this function have all option(filters) for the user to choose
	
	cout << "Press 1 to Make the Image B&W Image.\n"
		<< "Press 2 to Invert Image.\n"
		<< "Press 3 to Merge two Images.\n"
		<< "Press 4 to Flip the Image.\n"
		<< "Press 5 to Rotate Image.\n"
		<< "Press 6 to Darken and Lighten Image .\n ";

	int x; 
	cin >> x ; //the number of filter that the user choose

	while (x > 6 || x < 1) { // this is a limitaion for variable x to make the user don't input a number higher than 6 or lower than 1     
		cout << "invalid choice ,pleas try again." << endl;
		cin >> x;
	}

	switch (x) { 
	case 1:
      	//Frist Filter	
		break;
	case 2:
      	//seconed Filter	
		break;
	case 3:
      	//Third Filter	
		break;

	case 4:
      	//Fourth Filter	
		break;

	case 5:
      	//Fifth Filter	
		break;

	case 6:
      	//Sixth Filter	
		break;
	}
	 
}


void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}



void saveImage () {


   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}




void repeat_or_finish()  //this function made for asking the user after adding a filter if he want another filter for the same image that already had changes
{  
	//we will reapeat this function after every filter code  
	cout << "Press 1 to Add Another Filter \n"
		 << "Press 2 to End the Program \n"; 
	int y;
	cin >> y ; 
	if(y==1){
		main_menu(); 
	}
	else if(y==2){
		//don't do any thing(discard it to go to the save function after the main menu one)
	}
} 


// Create the Filter Functions Below Here