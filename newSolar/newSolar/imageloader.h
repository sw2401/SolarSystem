//Image Loader by Jacob
//ALL CODE REFERENCES AND METHODS CAN BE FOUND AT THE BOTTOM OF THE SOURCE.CPP FILE
#ifndef IMAGE_LOADER_H_INCLUDED
#define IMAGE_LOADER_H_INCLUDED

//Represents an image
class image {
public:
	image(char* ps, int w, int h);
	~image();

	char* pixels;
	int width;
	int height;
};

//Reads a bitmap image from file.
image* loadBMP(const char* filename);

#endif
#pragma once