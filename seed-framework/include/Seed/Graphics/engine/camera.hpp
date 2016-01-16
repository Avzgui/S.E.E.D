/*
* Copyright (c) <2015> <Antoine Richard and Jérémy Riffet, S.E.E.D>
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
* \file camera.hpp
* \author Jérémy RIFFET
* \version 0.1
* \copyright Copyright (c) 2015,
* Antoine "Avzgui" Richard and Jérémy "Chtimy" Riffet, S.E.E.D
* \license Zlib License.
*/

#ifndef CAMERA_HPP
#define CAMERA_HPP

//SEED INCLUDES
#include <Seed/Graphics/engine/Constant.hpp>

//OTHER INCLUDES
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <AntTweakBar.h>

class UBOBuffer;

/*! \class Camera
* \brief Camera class with matrix transformation attributes
*/
class Camera
{
public:
	/*!
	* \brief Constructor of class Camera
	* \param pos : Position of the camera
	* \param look : Position who looks the camera
	* \param upVector : The vertical vector of camera
	* \param FOV : The field of view of the camera
	* \param width : The width resolution of the screen
	* \param height : the height resolution of the screen
	* \param near : the min distance of field of view
	* \param far : the max distance of filed of view
	* \param WAngle : the horizontal angle
	* \param HAngle : the vertical angle
	* \param speed : speed of the translation of the camera
	* \param mouseSpeed : the speed of the mouse for the rotation
	*/
	Camera(glm::vec3 pos, glm::vec3 look, glm::vec3 upVector = glm::vec3(0.0,1.0,0.0), float FOV = 45, float width = WIDTH, float height = HEIGHT, float near = 0.1f, float far = 100.0f, float WAngle = 3.14f, float HAngle = 0.0f, float speed = (1.0f/30.0f), float mouseSpeed = (1.0f/200.0f));
	/*!
	* \brief Destructor of class Texture
	*/
	~Camera(){};
	/*!
	* \brief get the view matrix
	* \return glm::mat4 : View matrix
	*/
	glm::mat4 getViewMatrix();
	/*!
	* \brief get the projection matrix
	* \return glm::mat4 : Projection matrix
	*/
	glm::mat4 getProjectionMatrix();
	/*!
	* \brief get the position of the camera
	* \return the position of the camera
	*/
	glm::vec3 getPosition();
	/*!
	* \brief get the direction vector of the camera
	* \return the direction vector of the camera
	*/
	glm::vec3 getDirection();
	/*!
	* \brief get the up vector of the camera
	* \return the vector up of the camera
	*/
	glm::vec3 getUp();
	/*!
	* \brief get the horizontal angle
	* \return the horizontal angle
	*/
	float getWAngle();
	/*!
	* \brief get the vertical angle
	* \return the vertical angle
	*/
	float getHAngle();
	/*!
	* \brief get the near of the view
	* \return the near of the view
	*/
	float getNear();
	/*!
	* \brief get the far of the view
	* \return the far of the view
	*/
	float getFar();
	/*!
	* \brief get the speed of the camera translation
	* \return the speed of the camera translation
	*/
	float getSpeed();
	/*!
	* \brief get the mouse speed
	* \return the mouse speed
	*/
	float getMouseSpeed();
	/*!
	* \brief get the field of view
	* \return the field of view
	*/
	float getFoV();
	/*!
	* \brief get the initial field of view
	* \return the initial field of view
	*/
	const float getInitFoV();
	/*!
	* \brief set the vertical angle
	*/
	void setHAngle(float HAngle);
	/*!
	* \brief set the horizonal angle
	*/
	void setWAngle(float WAngle);

	glm::vec3 getRight();
	void setRight(glm::vec3 &right);


	/*!
	* \brief set the view matrix
	* \param pos : reference to the position of the camera
	* \param dir : reference to the direction of the camera
	* \param up : reference to the vertical vector of the camera
	*/
	void setViewMatrix(glm::vec3 &pos, glm::vec3 &dir, glm::vec3 &up);
	/*!
	* \brief set the view matrix
	* \param pos : reference to the position of the camera
	*/
	void setViewMatrix(glm::vec3 &pos);
	/*!
	* \brief set the projection matrix
	* \param Fov : reference to the field of view
	* \param width : reference to the width resolution
	* \param height : reference to the height resolution
	* \param near : reference to the min distance of field of view
	* \param far : reference to the max distance of field of view
	*/
	void setProjectionMatrix(const float &Fov, const int width, const int height, const float &near, const float &far);
	/**
	 * @brief      Update camera's Uniform Buffer Object
	 */
	void updateUBO();
	/**
	 * @brief      Get the UBO id of the camera
	 *
	 * @return     Id of the UBO camera
	 */
	unsigned int getUBOId();
	/*!
	* \brief set the mouse speed moving
	* \param speed : speed of the mouse's move
	*/
	void setMouseSpeed(const float speed);

	static void TW_CALL SetSpeedMouseCallback(const void *value, void *clientData)
	{
		static_cast<Camera *>(clientData)->setMouseSpeed(1.0/(*static_cast<const float *>(value)));
	}
	static void TW_CALL GetSpeedMouseCallback(void *value, void *clientData)
	{
		*static_cast<float *>(value) = static_cast<Camera *>(clientData)->getMouseSpeed();
	}

private:

	//structure for UBO for camera
	struct Matrix
	{
		glm::mat4 V;
		glm::mat4 P;
		glm::mat4 V_inverse;
	};

	struct Matrix matrix;

	glm::vec3 position, direction, up, right;
	//horizontal and vertical angle
	float WAngle, HAngle, near, far, FoV;
	float mouseSpeed, speed;
	//field of view
	float initFoV = 45.0;

	//UBO BUffer of the camera
	UBOBuffer *camBuf;
};



#endif