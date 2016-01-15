/*
* Copyright (c) <2015> <Antoine Richard and J�r�my Riffet, S.E.E.D>
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
*
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source distribution.
*/

/*!
* \file tga.hpp
* \author J�r�my RIFFET
* \version 0.1
* \copyright Copyright (c) 2015,
* Antoine "Avzgui" Richard and J�r�my "Chtimy" Riffet, S.E.E.D
* \license Zlib License.
*/

#ifndef TGA_HPP
#define TGA_HPP

#include <iostream>
#include <fstream>

struct tga_header
{
	unsigned char idLength;
	unsigned char colorMapType;
	unsigned char imageTypeCode;
	unsigned char colorMapSpec[5];
	unsigned short xOrigin;
	unsigned short yOrigin;
	unsigned short width;
	unsigned short height;
	unsigned char bpp;
	unsigned char imageDesc;
};


/*! \class TGA
* \brief Loading TGA image
*/
class TGA
{
public:

	bool Load(const char *filename);
	void release();

	char *imageData;
	tga_header tgaheader;
};

#endif
