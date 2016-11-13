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
* \file SimpleMaterial.hpp
* \brief Material of a node
* \author Jérémy RIFFET
* \version 0.1
* \copyright Copyright (c) 2015,
* Antoine "Avzgui" Richard and Jérémy "Chtimy" Riffet, S.E.E.D
* \license Zlib License.
*/

#ifndef SimpleMaterial_HPP
#define SimpleMaterial_HPP

//SEED INCLUDES
#include "Seed/Graphics/engine/material.hpp"

/*! \class SimpleMaterial
* \brief Material
*/
class SimpleMaterial : public Material
{
	public:

		/*!
		* \brief Constructor of class SimpleMaterial
		* \param material: address of the aimaterial
		* \param scene : adress of the scene
		* \param name: name of the material
		* \param reflection: weight of the reflective coefficient
		* \param refraction: weight of the refractive coefficient
		* \param flag: pointer of an int to get any errors
		*/
		SimpleMaterial(const aiMaterial *material, std::shared_ptr<Scene> scene, std::string name, unsigned int *flag = nullptr, const float reflec = 0.0, const float refrac = 0.0);
		/*!
		* \brief Constructor of class SimpleMaterial
		* \param scene: address of the scene
		* \param name: name of the material
		* \param reflection: weight of the reflective coefficient
		* \param refraction: weight of the refractive coefficient
		* \param flag: pointer of an int to get any errors
		*/
		SimpleMaterial(std::shared_ptr<Scene> scene, const std::string name, unsigned int *flag = nullptr, const float reflec = 0.0, const float refrac = 0.0);

		~SimpleMaterial();

		/*!
		* \brief Translate the model with vector T
		* \param T: tanslation vector
		*/
		void translateModel(glm::vec3 T);
		void scaleModel(glm::vec3 T);
		void rotateModel(glm::vec3 T);

		void render(Model *model);
		void render(){};
		void print(){};

	private:

		void init();
		GLuint m_block_index_lights[4];
		GLuint m_block_index_camera;

		std::shared_ptr<Shader> m_shader;
};

#endif