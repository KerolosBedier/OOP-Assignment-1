// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:                CS213-2023-20220252-20220051-20220024-A1-Part2.cpp
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
void black_and_white_image();// filter 1
void flip_image();// filter 4

void invert_image(); //filter 2
void rotate_image(); //filter 5

void merge_images(); //filter 3
void darken_and_lighten_image(); //filter 6



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
		<< "Press 6 to Darken and Lighten Image .\n"
		<< "Press 7 to Detect Image Edges.\n"
		<< "Press 8 to Enlarge Image.\n"
		<< "Press 9 to Shrink Image.\n"
		<< "Press 10 to Mirror Image.\n"
		<< "Press 11 to Shuffle Image.\n"
		<< "Press 12 to Blur Image.\n"
		<< "Press 13 to Crop Image.\n"
		<< "Press 14 to Skew Image.\n";


	int x; 
	cin >> x ; //the number of filter that the user choose

	while (x > 14 || x < 1) { // this is a limitaion for variable x to make the user don't input a number higher than 6 or lower than 1     
		cout << "invalid choice ,pleas try again." << endl;
		cin >> x;
	}

	switch (x) { 
	case 1:
        //first filter
        black_and_white_image();
		break;
	case 2:
      	//seconed Filter
         invert_image();
		break;
	case 3:
        //Third Filter
         merge_images();
		break;

	case 4:
        //fourth filter
        flip_image();
		break;

	case 5:
      	//Fifth Filter	
         rotate_image();
		break;

	case 6:
      	//Sixth Filter
         darken_and_lighten_image();
		break;

	case 7:
		// detact_image();
		break;
	
	case 8:
		// enlarge_image();
		break;
	
	case 9:
		// shrink_image();
		break;
	

	case 10:
		// miror_image();
		break;

	case 11:
		// shuffle_image();
		break;

	case 12:
		// blur_image();
		break;	
	
    case 13:
		// crop_image();
		break;	        
	
    case 14:
		// skew_image();
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

//Adham Salah's Filters(1,4)

void black_and_white_image() //filter 1
{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++) {
            if (image[i][j] > 127) // the white value of pixel is 255 and the black one is 0 so we need to turn every pixel above the avarage(127) is white and under that is black
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    repeat_or_finish();

}


void flip_image() //filter 4
{ 
    //frist thing we need to have a copied image for the orginal we have
    unsigned char image2[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image2[i][j] = image[i][j];
        }
    }

    cout << "Do you want to  Flip the Image Horizontally or Vertically? \n"
         << "Press 1 to Flip Horizontally \n"
         << "Press 2 to Flip Vertically \n";

    int x;
    cin >> x;

    while (x > 2 || x < 1) {  // this is a limitaion for variable x to make the user don't input a number higher than 2 or lower than 1
        cout << "invalid choice ,please try again." << endl;
        cin >> x;
    }

    if(x==1){ //Flip Horizontally loop

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[SIZE-i-1][j]=image2[i][j];
                /* in horizontal flip the column will be the same(dont change)
                 and the row will go to last index in the row index */
            }
        }
    }


    else if(x==2){  //Flip Vertically loop

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i][SIZE-j-1]=image2[i][j];
                /* in Vertical flip the column will be the same(dont change)
                 and the row will go to last index in the row index */
            }
        }

    }
    repeat_or_finish();

}
//============================================================================

// Kerolos Bedier's Filter (2 , 5)

void invert_image() // Filter 2
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
          //operation to each pixel in the image is that dark areas become light and light areas become dark
            image[i][j] = 255-image[i][j];
		}
	}
    repeat_or_finish();
	
}



void rotate_image() //Filter 5
{ 
	unsigned char copied_image[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
        	copied_image[i][j] = image[i][j];
		}
	}

	cout << "Press 1 to Routate the Image for 90 degrees \n" 
		 << "Press 2 to Routate the Image for 180 degrees \n"
		 << "Press 3 to Routate the Image for 270 degrees \n";

	int x ; 
	cin >> x ; 

	while (x > 3 || x < 1) {   // this is a limitaion for variable x to make the user don't input a number higher than 3 or lower than 1     
		cout << "invalid choice ,please try again." << endl;
		cin >> x;
	}	
	
			if(x==1){ //90 degrees loop
				for (int i = 0; i < SIZE; i++) {
    				for (int j = 0; j< SIZE; j++) {
						image[j][SIZE - 1 - i] = copied_image[i][j] ;
						/* 90 degrees rotate the value of column will be the same and sawp index will change in the row index
				 		and sawp the row index with the column index with the change the value of it */
    				}
  				}
			}

			else if(x==2){ //180 degrees loop
				for (int i = 0; i < SIZE; i++) {
    				for (int j = 0; j< SIZE; j++) {
						image[SIZE - 1 - i][SIZE - 1 - j] = copied_image[i][j] ;
						/* 180 sawp the column index with the column index with the change the value of it
				 		and sawp the row index with the column index with the change the value of it */						
    				}
  				}	
			}
			else if(x==3){ //270 degrees loop
				for (int i = 0; i < SIZE; i++) {
    				for (int j = 0; j< SIZE; j++) {
						image[SIZE - 1 - j][i] = copied_image[i][j] ;
						/* 180 sawp the column index with the column index with the change the value of it
				 		and rotate the value of row will be the same and sawp index will change in the column index */						
    				}
  				}
			}
    repeat_or_finish();
}

    //Another sulotion for rotate image function
	
    // switch (x)
	// {
	// case 1:
	// 	for (int i = 0; i < SIZE; i++) {
    // 		for (int j = 0; j< SIZE; j++) {
	// 			image[j][255 - i] = copied_image[i][j] ;
    // 		}
  	// 	}
	// break;
	
	// case 2:
	// 	for (int i = 0; i < SIZE; i++) {
    // 		for (int j = 0; j< SIZE; j++) {
	// 			copied_image[j][255 - i] = image[i][j] ;
    // 		}
  	// 	}

	// 	for (int i = 0; i < SIZE; i++) {
    // 		for (int j = 0; j< SIZE; j++) {
	// 			image[j][255 - i] = copied_image[i][j] ;
    // 		}
  	// 	}		
	// break;

	// case 3:
	// 	for (int i = 0; i < SIZE; i++) {
    // 		for (int j = 0; j< SIZE; j++) {
	// 			image[j][255 - i] = copied_image[i][j] ;
    // 		}
  	// 	}		

	// 	for (int i = 0; i < SIZE; i++) {
    // 		for (int j = 0; j< SIZE; j++) {
	// 			copied_image[j][255 - i] = image[i][j] ;
    // 		}
  	// 	}


	// 	for (int i = 0; i < SIZE; i++) {
    // 		for (int j = 0; j< SIZE; j++) {
	// 			image[j][255 - i] = copied_image[i][j] ;
    // 		}
  	// 	}
	// break;
	// }


//==========================================================================


// Ahmed Atef filters (3,6)

void merge_images() //filter 3
{
    //frist ting we need to add a new(another) image to the programm
    unsigned char image2[SIZE][SIZE];
    char imageFileName[100];

    cout << "Enter Another Source Image File name to Merge: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] = (image[i][j] + image2[i][j])/2;
            // to merge we get the same pixel in the frist image and the seconed one
            // and add the two value and divide them to have the closet valve(color) between the two pixels
        }
    }
    repeat_or_finish();

}


void darken_and_lighten_image() { //filter 6

    cout << "Do you want to (d)arken or (l)ighten? \n"
         << "Press 1 to Darken the Image \n"
         << "Press 2 to Lighten the Image \n";

    int x;
    cin >> x;

    while (x > 2 || x <
                    1) { // this is a limitaion for variable x to make the user don't input a number higher than 2 or lower than 1
        cout << "invalid choice ,pleas try again." << endl;
        cin >> x;
    }

    if (x == 1) {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = (image[i][j]) / 2;
            }
        }
    }


    if (x == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = (255 + image[i][j]) / 2;
                // merge the photo with white pixels

            }
        }
    }
    repeat_or_finish();
}