

#include <iostream>
using namespace std;
#include "Image_Class.h"
void black_and_white(Image& image) 
    {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            double avg = 0;
            for (int k = 0; k < 3; k++) {
                avg += image(i, j, k);
            }
            avg /= 3;
            for (int k = 0; k < 3; k++) {
                if (avg > 127.5) {
                    image(i, j, k) = 255;
                }
                else if (avg < 127.5) {
                    image(i, j, k) = 0;
                }
            }
        }
    }

}
void gray_scale(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);}
            avg /= 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}
void invert_image(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
}
void flip(Image& image) {
    string choice;
    cout << "[a] to Flip Vertically";
    cout << "\n[b] to Flip Horizontally\n";
    cin >> choice;
    Image image1 = image;
    if (choice == "a" || choice == "A") {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = image1(i, image.height - j - 1, k);
                }
            }
        }
    }
    else if (choice == "b" || choice == "B") {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = image1(image.width - i - 1, j, k);
                }
            }
        }
    }
   
}
void rotate_image(Image& image) {
    int angle;
    cout<<"Enter rotation angle(90, 180, or 270):";
    cin>>angle;
    if (angle == 90) {
        Image rotated( image.height,image.width );
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    rotated.setPixel(image.height - 1 - j,i,k,image.getPixel(i,j,k));
                    image = rotated;



                            }
                        }
                    }
                }else if (angle == 180) {
                    Image rotated( image.width,image.height );
                    for (int i = 0; i < image.width; ++i) {
                        for (int j = 0; j < image.height; ++j) {
                            for (int k = 0; k < 3; ++k) {
                                rotated.setPixel(image.width - 1 - i, image.height - 1 - j,k,image.getPixel(i,j,k));
                                image = rotated;
                            }
                        }
                    }
                }else if (angle == 270) {
                    Image rotated( image.height,image.width );
                    for (int i = 0; i < image.width; ++i) {
                        for (int j = 0; j < image.height; ++j) {
                            for (int k = 0; k < 3; ++k) {
                                rotated.setPixel(j,image.width - 1 - i,k,image.getPixel(i,j,k));
                                image = rotated;
                            }
                        }
                    }
                }
            }
void darken_lighten(Image& image) {
    int choise;
    cout<<"Enter 1 for Darken or 2 for Lighten: ";
    cin>>choice;
    if (choice == 1) {
        for (int i = 0; i < image.height; ++i) {
            for (int j = 0; j < image.width; ++j) {
                for (int k = 0; k < 3; ++k) {

                }
            }
        }
    }else if (choice == 2) {
        for (int i = 0; i < image.height; ++i) {
            for (int j = 0; j < image.width; ++j) {
                for (int k = 0; k < 3; ++k) {

                }
            }
        }
    }
}



int main() {
    string filename;
    cout << "Pls enter image name: ";
    cin >> filename;

    Image image(filename);

    cout << "Choose filter:\n";
    cout << "1. Convert to Gray Scale\n";
    cout << "2. Convert to Black and White\n";
    cout << "3. Invert Image\n";
    cout << "4. Merge Images\n";
    cout << "5. rotate image\n";
    cout << "6. darken_lighten(image)\n";
    cout << "Enter choice (1, 2, 3,4,5 or 6): ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        gray_scale(image);
        cout << "Image converted to Gray Scale successfully.\n";
    } else if (choice == 2) {
        black_and_white(image);
        cout << "Image converted to Black and White successfully.\n";
    } else if (choice == 3) {
        invert_image(image);
        cout << "Image inverted successfully.\n";
    } else if (choice == 4) {
        flip(image);
        cout << "Image flipped successfully.\n";
    } else if (choice == 5) {
        rotate_image(image);
        cout << "Image rotated successfully.\n";
    } else if (choice == 6) {
        darken_lighten(image);
        cout << "Darken image successfully.\n";
    } else {
        cout << "Invalid choice.\n";
    }


    cout << "\nPls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;

    image.saveImage(filename);

    return 0;
}