

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
    cout << "Enter choice (1, 2, 3, or 4): ";

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
    } else {
        cout << "Invalid choice!\n";
        return 1;
    }

    cout << "\nPls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;

    image.saveImage(filename);

    return 0;
}