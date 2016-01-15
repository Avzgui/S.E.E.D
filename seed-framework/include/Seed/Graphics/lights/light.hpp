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
* \file light.hpp
* \brief Lights of the scene
* \author J�r�my RIFFET
* \version 0.1
* \copyright Copyright (c) 2015,
* Antoine "Avzgui" Richard and J�r�my "Chtimy" Riffet, S.E.E.D
* \license Zlib License.
*/


#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <map>

/*! \class Light
* \brief Light of the scene
*/
class Light
{
public:
	/*!
	* \brief Constructor of class Light
	* \param name name of the light
	* \param color color of the light
	*/
	Light(const std::string &name, const glm::vec3 &color);
	/*!
	* \brief Destructor of class Light
	*/
	~Light();
	/*!
	* \brief Get color of the light
	* \return Color of the light
	*/
	glm::vec3 getColor();
	/*!
	* \brief get the name of the light
	* \return the name of hte light
	*/
	std::string getName();
	virtual void afficher() = 0;

private:
	std::string name;
	glm::vec3 color;
	
};

#endif