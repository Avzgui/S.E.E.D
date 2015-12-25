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
* \file material.hpp
* \brief Material of a node
* \author J�r�my RIFFET
* \version 0.1
* \copyright Copyright (c) 2015,
* Antoine "Avzgui" Richard and J�r�my "Chtimy" Riffet, S.E.E.D
* \license Zlib License.
*/

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <GL/glew.h>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <Seed/Graphics/texture.hpp>
#include <Seed/Graphics/model/model.hpp>
#include <Seed/Graphics/scene.hpp>
#include <Seed/Graphics/camera.hpp>
#include <Seed/Graphics/Constant.hpp>

class Scene;
class Shader;
/*! \class Material
* \brief Material of a node
*/
class Material
{
	public:

		/*!
		* \brief Constructor of class Material
		* \param material: address of the aimaterial
		* \param scene: address of the scene
		* \param flag: pointer of an int to get any errors
		* \param reflection: weight of the reflective coefficient
		* \param rafraction: weight of the refractive coefficient
		* \param name: name of the material
		*/
		Material(const aiMaterial *material, Scene *scene, std::string name, unsigned int *flag = nullptr, const float reflec = 0.0, const float refrac = 0.0);
		/*!
		* \brief Constructor of class Material
		* \param scene: address of the scene
		* \param name: name of the material
		* \param flag: pointer of an int to get any errors
		* \param reflection: weight of the reflective coefficient
		* \param rafraction: weight of the refractive coefficient
		* \param pathShaders: path to the directory who contains shaders' files
		*/
		Material(Scene *scene, const std::string name, unsigned int *flag = nullptr, const float reflec = 0.0, const float refrac = 0.0, const std::string pathShaders = "");

		~Material();

		/*!
		* \brief Load shaders from the directory "Shaders" in directory of this material
		* \param pathDir: path to the directory of the shaders
		*/
		bool addShaders(const std::string pathDir);

		//virtual void render(Model *model) = 0;
		//virtual void render();
		/*!
		* \brief Push texture in the textures' array
		* \param t: Address of texture to push
		*/
		void pushTexture(Texture *texture);
		/*!
		* \brief adding texture to the material since the textur es' folder
		* \param path to the texture
		* \param scene: address of the current scene
		* \return true if the texture is adding
		*/
		void addTexture(const std::string pathTexture, Scene *scene, unsigned int type, unsigned int *flag = NULL);
		/*!
		* \brief setting composants of material
		* \param a: ambiant composant
		* \param d: diffuse composant
		* \param s: specular composant
		*/
		void setLight(float a, float d, float s);
		/*!
		* \brief Active textures
		*/
		void activeTextures();
		/*!
		* \brief Release textures
		*/
		void releaseTextures();

		/*!
		* \brief Print textures
		*/
		void printTextures();

		virtual void render(){};
		virtual void render(Model *m){};

		virtual void print() = 0;

	protected:

		Shader *shader;
		std::vector<Texture*> textures_ambiant;
		std::vector<Texture*> textures_diffuse;
		std::vector<Texture*> textures_specular;
		Texture* texture_normal;
		Scene *scene;
		Camera *camera;
		std::string name;

		/*!
		* \brief activate shaders
		* \return true if the shader is activated
		*/
		bool activateShader();

		struct compLight
		{
			float ambiant, diffuse, specular;
			GLuint ambiantID, diffuseID, specularID;
		};

		struct Mat
		{
			float Ks;
			float Kr;
		};

		glm::mat4 Normal_Matrix;
		uniform MID, NMID, matID, NMACTIVEID,SMACTIVEID, SMVIEWID;
		compLight compl;
		Mat mat;
};

#endif