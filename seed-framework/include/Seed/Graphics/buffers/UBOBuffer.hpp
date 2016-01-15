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
* \file UBOBuffer.hpp
* \brief Uniform Buffer Object
* \author J�r�my RIFFET
* \version 0.1
* \copyright Copyright (c) 2015,
* Antoine "Avzgui" Richard and J�r�my "Chtimy" Riffet, S.E.E.D
* \license Zlib License.
*/


#ifndef UBOBUFFER_HPP
#define UBOBUFFER_HPP

//SEED INCLUDES
#include <Seed/Graphics/engine/tools.hpp>

//OTHER INCLUDES
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>


/*! \class UBOBuffer
* \brief Create, update, delete UBOBuffers
*/
class UBOBuffer
{
public:
	/*!
	* \brief Constructor of class UBOBuffer
	*/
	UBOBuffer();
	/*!
	* \brief Destructor of class UBOBuffer
	*/
	~UBOBuffer();
	/*!
	* \brief Create UBOBuffer
	* \param size: size of the buffer
	* \return true if the creation is a success
	*/
	void createBuffer(int size);
	/*!
	* \brief Update UBOBuffer
	* \param data pointer to the datas
	* \param size size of the datas
	*/
	void updateBuffer(void* data, int size);
	/*!
	* \brief delete UBOBuffer
	*/
	void deleteBuffer();
	/*!
	* \brief get Id of the UBO buffer
	* \return ID of the UBO buffer
	*/
	GLuint getID();

private:
	GLuint UBOID;
	int size;
};

#endif