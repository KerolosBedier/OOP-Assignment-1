// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:                CS213-2023–20220252-20220051-20220024-A1Bonus
// Last Modification Date:      19/10/2023
// Author1 and ID and Group:    Kerolos Bedier Soliman - 20220252 - S13
// Author2 and ID and Group:    Adham salah ezzat  - 20220051 - S7
// Author3 and ID and Group:    Ahmed Atef Mohamed - 20220024 - S7
// Teaching Assistant:          N/A
// Purpose:                     Assignment 1 Image Processor

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"


using namespace std;
unsigned char image[SIZE][SIZE][RGB];

void main_menu();
void loadImage ();
void saveImage ();
void repeat_or_finish(); 


// THE FUNCTIONS TO DO TO THE PHOTO 
void black_and_white_image(); //Filter 1
void invert_image(); //Filter 2
void merge_images(); //Filter 3
void flip_image(); //Filter 4 
void rotate_image(); //Filter 5
void darken_and_lighten_image(); //Filter 6 
void detact_image(); //Filter 7
void enlarge_image(); //Filter 8
void shrink_image(); //Filter 9
void miror_image(); //Filter a
void shuffle_image(); //Filter b
void blure_image(); //Filter c 
void crop_image(); //Filter d 
void skew_image(); //Filter e&f
void skew_herizontally(); //Filter e
void skew_vertically(); //Filter f


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
      	black_and_white_image();	
		break;
	case 2:
		invert_image();
		break;
	case 3:
		merge_images();
		break;

	case 4:
		flip_image();
		break;

	case 5:
		rotate_image();
		break;

	case 6:
		darken_and_lighten_image();
		break;

	
	case 7:
		detact_image();
		break;
	
	case 8:
		enlarge_image();
		break;
	
	case 9:
		shrink_image();
		break;
	

	case 10:
		miror_image();
		break;

	case 11:
		shuffle_image();
		break;

	case 12:
		blure_image();
		break;	
	
    case 13:
		crop_image();
		break;	        
	
    case 14:
		skew_image();
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
   readRGBBMP(imageFileName, image);
}



void saveImage () {


   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
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



//==================================================================================================================

void black_and_white_image()
{
	//Taking the avrage of 3d array 256*256*256 
	for (int i = 0; i < SIZE; i++){
    	for (int j = 0; j< SIZE; j++) { 
				if (image[i][j][0] + image[i][j][1] + image[i][j][2] > 127*3){  //If the pixel > avarage turn it to a white 
        			image[i][j][0] = 255;
        			image[i][j][1] = 255;
        			image[i][j][2] = 255;
				}
				else{ //If the pixel > avarage turn it to a black
            		image[i][j][0] = 0;
            		image[i][j][1] = 0;
            		image[i][j][2] = 0;
        		}
    }
  }        

  
  repeat_or_finish();

}		

//==================================================================================================================

void invert_image() //take the value of the pixel and subtract it from SIZE 
{
 for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) { 
        for (int k = 0; k < RGB; k++) {
            image[i][j][k] = 255 - image[i][j][k];
        }
    }
}
    repeat_or_finish();
	
}

//==================================================================================================================

void merge_images()
{
	//frist ting we need to add a new(another) image to the programm 
	unsigned char image2[SIZE][SIZE][RGB];
	char imageFileName[100];

   cout << "Enter Another Source Image File name to Merge: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image2);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j< SIZE; j++) {
			for(int k = 0; k< RGB; k++){ //as same as the gray but with another diminsion
				image[i][j][k] = (image[i][j][k] + image2[i][j][k])/2;
		// to merge we get the same pixel in the frist image and the seconed one 
		// and add the two value and divide them to have the closet valve(color) between the two pixels
			}
		}
  	}
	repeat_or_finish();

}

//==================================================================================================================

void flip_image(){
	//frist thing we need to have a copied image for the orginal we have 
	unsigned char image2[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
	    	for (int k = 0; k< RGB; k++){
        		image2[i][j][k] = image[i][j][k];
			}
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
	    		for (int k = 0; k< RGB; k++) {

            	image[SIZE-i-1][j][k]=image2[i][j][k]; 
				/* in horizontal flip the column will be the same(dont change)
				 and the row will go to last index in the row index */
				}
			}
		}
  	}


	else if(x==2){  //Flip Vertically loop

		for (int i = 0; i < SIZE; i++) {
        	for (int j = 0; j< SIZE; j++) {
	    		for (int k = 0; k< RGB; k++) {
            	image[i][SIZE-j-1][k]=image2[i][j][k];
				/* in Vertical flip the column will be the same(dont change)
				 and the row will go to last index in the row index */
				}
			}
		}
		
	}
    repeat_or_finish();
  	
}

//==================================================================================================================

void rotate_image(){ 
	unsigned char copied_image[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
	    	for (int k = 0; k< RGB; k++){
        		copied_image[i][j][k] = image[i][j][k];
			}
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
	    				for (int k = 0; k< RGB; k++){
							image[j][SIZE - 1 - i][k] = copied_image[i][j][k] ;
						/* 90 degrees rotate the value of column will be the same and sawp index will change in the row index
				 		and sawp the row index with the column index with the change the value of it */
						}
					}
  				}
			}

			else if(x==2){ //180 degrees loop
				for (int i = 0; i < SIZE; i++) {
    				for (int j = 0; j< SIZE; j++) {
	    				for (int k = 0; k< RGB; k++){
							image[SIZE - 1 - i][SIZE - 1 - j][k] = copied_image[i][j][k] ;
						/* 180 sawp the column index with the column index with the change the value of it
				 		and sawp the row index with the column index with the change the value of it */						
						}
					}
  				}	
			}
			else if(x==3){ //270 degrees loop
				for (int i = 0; i < SIZE; i++) {
    				for (int j = 0; j< SIZE; j++) {
	    				for (int k = 0; k< RGB; k++){
							image[SIZE - 1 - j][i][k] = copied_image[i][j][k] ;
						/* 180 sawp the column index with the column index with the change the value of it
				 		and rotate the value of row will be the same and sawp index will change in the column index */						
						}
					}
  				}
			}
    repeat_or_finish();
}

// //==================================================================================================================

void darken_and_lighten_image(){

	cout << "Do you want to (d)arken or (l)ighten? \n"  
		 << "Press 1 to Darken the Image \n" 
		 << "Press 2 to Lighten the Image \n";

	int x;
	cin >> x;

	while (x > 2 || x < 1) { // this is a limitaion for variable x to make the user don't input a number higher than 2 or lower than 1     
		cout << "invalid choice ,pleas try again." << endl;
		cin >> x;
	}

	if(x==1){

		for (int i = 0; i < SIZE; i++) {
	    	for (int j = 0; j< SIZE; j++) {
				for (int k = 0; k< RGB; k++){
        			image[i][j][k] = (image[i][j][k])/2;
				}
			}
		}
  	}


	if(x==2){
		for (int i = 0; i < SIZE; i++) {
	    	for (int j = 0; j< SIZE; j++) {
				for (int k = 0; k< RGB; k++){
        			image[i][j][k] = (255 + image[i][j][k])/2;
				// merge the photo with white pixels
				}	
			}
		}
  	}
    repeat_or_finish();

}
//==================================================================================================================

void detact_image(){
	unsigned char copied_image[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
	    	for (int k = 0; k< RGB; k++){
        		copied_image[i][j][k] = image[i][j][k];
			}
		}
	}
	
  	for (int i = 0; i < SIZE; i++){
    	for (int j = 0; j< SIZE; j++) {  
				if (copied_image[i][j][0] + copied_image[i][j][1] + copied_image[i][j][2] > 127*3){ 
        			copied_image[i][j][0] = 255;
        			copied_image[i][j][1] = 255;
        			copied_image[i][j][2] = 255;
				}
				else{
            		image[i][j][0] = 0;
            		image[i][j][1] = 0;
            		image[i][j][2] = 0;
        		}
    }
  }        
       
	

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
			for (int k = 0; k< RGB; k++){
        		if (copied_image[i][j][k] == 0 && copied_image[i][j-1][k]==0 && copied_image[i][j+1][k]==0 && copied_image[i-1][j][k]==0 && copied_image[i+1][j][k]==0 ){
					image[i][j][k] = 255;
				}
			}		
		}		
	}

    repeat_or_finish();
}

//==================================================================================================================

void enlarge_image()
{
	unsigned char copied_image[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
	    	for (int k = 0; k< RGB; k++){
        		copied_image[i][j][k] = image[i][j][k];
			}
		}
	}

	int x ;
	cout << "Which quarter to enlarge 1, 2, 3 or 4?" << endl ;
	cin >> x ; 

	while (x > 4 || x < 1) {  // this is a limitaion for variable x to make the user don't input a number higher than 2 or lower than 1   
		cout << "invalid choice ,please try again." << endl;
		cin >> x;
	}

	if(x==1)
	{
		for (int i = 0; i < SIZE; i++) {
	    	for (int j = 0; j< SIZE; j++) {
				for (int k = 0; k< RGB; k++){
        			image[i][j][k] = copied_image[i/2][j/2][k];
				}
			}
		}	
	}

	if(x==2)
	{
		for (int i = 0; i < SIZE; i++) {
	    	for (int j = 0; j< SIZE; j++) {
				for (int k = 0; k< RGB; k++){				
        			image[i][j][k] = copied_image[i/2][(j/2)+128][k];
				}
			}
		}	
	}

	if(x==3)
	{
		for (int i = 0; i < SIZE; i++) {
	    	for (int j = 0; j< SIZE; j++) {
				for (int k = 0; k< RGB; k++){				
        			image[i][j][k] = copied_image[(i/2)+128][j/2][k];
				}			
			}
		}	
	}

	if(x==4)
	{
		for (int i = 0; i < SIZE; i++) {
	    	for (int j = 0; j< SIZE; j++) {
				for (int k = 0; k< RGB; k++){				
        			image[i][j][k] = copied_image[(i/2)+128][(j/2)+128][k];
				}
			}
		}	
	}
    repeat_or_finish();
}

//==================================================================================================================

void shrink_image(){

	unsigned char copied_image[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
	    	for (int k = 0; k< RGB; k++){
        		copied_image[i][j][k] = image[i][j][k];
				image[i][j][k] = 255 ; 
			}
		}
	}

    cout<<"Shrink to (1/2) Press 1, (1/3) Press 2 or (1/4) Press 3?   " ;

    int x ;
    cin>>x;

    while (x > 3 || x < 1) {  // this is a limitaion for variable x to make the user don't input a number higher than 2 or lower than 1
        cout << "invalid choice ,please try again." << endl;
        cin >> x;
    }

    if(x==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i / 2][j / 2][0] = copied_image[i][j][0];
                image[i / 2][j / 2][1] = copied_image[i][j][1];
                image[i / 2][j / 2][2] = copied_image[i][j][2];
			}
        }
    }

    else if (x==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {			
                image[i / 3][j / 3][0] = copied_image[i][j][0];
                image[i / 3][j / 3][1] = copied_image[i][j][1];
                image[i / 3][j / 3][2] = copied_image[i][j][2];
            }
        }
    }

    else if (x==3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i / 4][j / 4][0] = copied_image[i][j][0];
                image[i / 4][j / 4][1] = copied_image[i][j][1];
                image[i / 4][j / 4][2] = copied_image[i][j][2];
            }
        }
    }

    repeat_or_finish();
}

//==================================================================================================================

void miror_image(){
	
	char x ; 
	cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?" << endl; 
	cin >> x ;


	if( x == 'l' ){
		for (int i = 0; i < SIZE; i++) {
	    	for (int j = 0; j< SIZE/2; j++) {
				for (int k = 0; k< RGB; k++){				
        			image[i][SIZE -j][k] = image[i][j][k]; 
				}
			}
		}
	}

	if( x == 'r' ){
		for (int i = 0; i < SIZE; i++) {
	    	for (int j = 0; j< SIZE/2; j++) {
				for (int k = 0; k< RGB; k++){				
        			image[i][j][k] = image[i][SIZE - j][k]; 
				}
			}
		}
	}


	if( x == 'u' ){
		for (int i = 0; i < SIZE/2; i++) {
	    	for (int j = 0; j< SIZE; j++) {
				for (int k = 0; k< RGB; k++){				
        			image[SIZE - i][j][k] = image[i][j][k]; 
				}
			}
		}
	}

	if( x == 'd' ){
		for (int i = 0; i < SIZE/2; i++) {
	    	for (int j = 0; j< SIZE; j++) {
				for (int k = 0; k< RGB; k++){				
        			image[i][j][k] = image[SIZE - i][j][k]; 
				}
			}
		}
	}
    repeat_or_finish();
}

//==================================================================================================================

void shuffle_image(){

	unsigned char copied_image[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
	    	for (int k = 0; k< RGB; k++){
        		copied_image[i][j][k] = image[i][j][k];
			}
		}
	}

	int x , y , z , q ; 
	cin >> x >> y >> z >> q ;  

	for (int i = 0; i < SIZE/2; i++) {
    	for (int j = 0; j< SIZE/2; j++) {
			for (int k = 0; k< RGB; k++){			
		// Moving Into Frist Part
			if(x==2){
				image[i][j][k] = copied_image[i][j+128][k];
			}
			else if(x==3){
				image[i][j][k] = copied_image[i][j+128][k];
			}
			else if(x==4){
				image[i][j][k] = copied_image[i+128][j+128][k];
			}			

			// Moving Into Seconed Part	
			if(y==1){
				image[i][j+128][k] = copied_image[i][j][k];
			}
			else if(y==3){
				image[i][j+128][k] = copied_image[i+128][j][k];
			}
			else if(y==4){
				image[i][j+128][k] = copied_image[i+128][j+128][k];
			}			


		// Moving Into Third Part	
			if(z==1){
				image[i+128][j][k] = copied_image[i][j][k];
			}
			else if(z==2){
				image[i+128][j][k] = copied_image[i][j+128][k];
			}
			else if(z==4){
				image[i+128][j][k] = copied_image[i+128][j+128][k];
			}	



		// Moving Into Forth Part	
			if(q==1){
				image[i+128][j+128][k] = copied_image[i][j][k];
			}
			else if(q==2){
				image[i+128][j+128][k] = copied_image[i][j+128][k];
			}
			else if(q==3){
				image[i+128][j+128][k] = copied_image[i+128][j][k];
			}

			}
    	}
  	}
    repeat_or_finish();
}

//==================================================================================================================

void blure_image(){
	int pixel_size = 7; // Adjust this to change the blur intensity
	int half_pixel_size = pixel_size / 2;

	for (int i = 0; i < SIZE ; i++) {
    	for (int j = 0; j < SIZE ; j++) {
			for (int k = 0; k< RGB; k++){
	       		int sum = 0;

    	   		for (int x = -half_pixel_size; x <= half_pixel_size; x++) {
        	    	for (int y = -half_pixel_size; y <= half_pixel_size; y++) {
        	    		sum += image[i + x][j + y][k];
        			}
        		}

        		int num_pixels = pixel_size * pixel_size;
        		image[i][j][k] = sum / num_pixels;
			}
	   }
	}
    repeat_or_finish();
}

//==================================================================================================================

void crop_image()
{
    int x, y, length, width;

    // Get user input for x, y, length, and width
    cout << "Enter x position: ";
    cin >> x;
    cout << "Enter y position: ";
    cin >> y;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;


    // Perform cropping
    unsigned char croppedImage[SIZE][SIZE][RGB];

    for (int i = y; i < y + length && i < SIZE; i++) {
        for (int j = x; j < x + width && j < SIZE; j++) {
            croppedImage[i - y][j - x][0] = image[i][j][0];
            croppedImage[i - y][j - x][1] = image[i][j][1];
            croppedImage[i - y][j - x][2] = image[i][j][2];
        }
    }

    // Copy the cropped image back to the original image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
            	if (i < y || i >= y + length || j < x || j >= x + width) {
                	image[i][j][k] = 255; // Set pixels outside the crop area to white
           		} 
				else {
                	image[i][j][k] = croppedImage[i - y][j - x][k];
            	}
			}
		}
    }

    repeat_or_finish();
}

//==================================================================================================================

void skew_image()
{
	cout << "Press 1 to Skew Herizontally \n"
		<< "Press 2 to Skew Vertically \n" ;

	int z ; 
	cin >> z ; 

	if(z==1)
		skew_herizontally(); 
	
	else if(z==2)
		 skew_vertically();

	
repeat_or_finish();	
}


void skew_herizontally()
{
	unsigned char copied_image[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
	    	for (int k = 0; k< RGB; k++){
        		copied_image[i][j][k] = image[i][j][k];
			}
		}
	}

	int degree;
	cout << "Please enter degree to skew right: " ; 
	cin >> degree; 

	while (degree == 90 || degree == -90) {  
		cout << "invalid choice ,please try again." << endl;
		cin >> degree;
	}	

	float raduis = (degree*M_PI)/180; 

	int x = 1 + (1/tan(raduis));
    double step = SIZE - 256/x ;
	double mov = step/SIZE ;
	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j<SIZE; j++) {
			copied_image[i][j/x][0] = image[i][j][0];
			copied_image[i][j/x][1] = image[i][j][1];
			copied_image[i][j/x][2] = image[i][j][2];
        }
	}

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j<SIZE; j++) {
			for (int k = 0; k<SIZE; k++) {
				image[i][j][k] = 255;
			}
        }
	}


	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j<SIZE/x; j++) {
			image[i][j+(int)step][0] = copied_image[i][j][0] ;
			image[i][j+(int)step][1] = copied_image[i][j][1] ;
			image[i][j+(int)step][2] = copied_image[i][j][2] ;
		}
		step -= mov;
	}
}


void skew_vertically()
{
	unsigned char copied_image[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j< SIZE; j++) {
	    	for (int k = 0; k< RGB; k++){
        		copied_image[i][j][k] = image[i][j][k];
			}
		}
	}

	int degree;
	cout << "Please enter degree to skew right: " ; 
	cin >> degree; 

	while (degree == 90 || degree == -90) {  
		cout << "invalid choice ,please try again." << endl;
		cin >> degree;
	}	

	float raduis = (degree*M_PI)/180; 

	int x = 1 + (1/tan(raduis));
    double step = SIZE - 256/x ;
	double mov = step/SIZE ;
	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j<SIZE; j++) {
			copied_image[i/x][j][0] = image[i][j][0];
			copied_image[i/x][j][1] = image[i][j][1];
			copied_image[i/x][j][2] = image[i][j][2];
        }
	}

	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j<SIZE; j++) {
			for (int k = 0; k<SIZE; k++) {
				image[i][j][k] = 255;
			}
        }
	}


    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i<SIZE/x; i++) {
            image[i+(int)step][j][0] = copied_image[i][j][0] ;
            image[i+(int)step][j][1] = copied_image[i][j][1] ;
            image[i+(int)step][j][2] = copied_image[i][j][2] ;
        }
        step -= mov;
    }

}




