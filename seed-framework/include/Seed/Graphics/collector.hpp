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
* \file collector.hpp
* \author Jérémy RIFFET
* \version 0.1
* \copyright Copyright (c) 2015,
* Antoine "Avzgui" Richard and Jérémy "Chtimy" Riffet, S.E.E.D
* \license Zlib License.
*/

#ifndef COLLECTOR_HPP
#define COLLECTOR_HPP

#include <iostream>
#include <vector>
#include <Seed/Graphics/node.hpp>
class Texture;
class Light;
class Model;
class Material;
class Node;
/*! \class Collector
* \brief Collector class collects nodes in vectors
*/
class Collector
{
public:
	/*!
	* \brief Constructor of class Collector
	*/
	Collector();
	/*!
	* \brief Destructor of class Collector
	*/
	~Collector();

	/*!
	* \brief Collects rendered nodes without lights
	* \param rootNode: root node of the scene
	*/
	void collectRenderedNodes(Node* rootNode);
	/*!
	* \brief Collects rendered nodes
	* \param rootNode: root node of the scene
	*/
	void collectRenderedLightingNodes(Node* rootNode);

	/*!
	* \brief Collect material
	* \param material to collect
	*/
	void collectMaterials(Material *material);
	/*!
	* \brief Collect materials
	* \param materials to collect
	*/
	void collectMaterials(std::vector<Material*> materials);
	/*!
	* \brief Collect texture
	* \param texture to collect
	*/
	void collectTextures(Texture* texture);
	/*!
	* \brief Collect textures
	* \param textures to collect
	*/
	void collectTextures(std::vector<Texture*> textures);
	/*!
	* \brief Collect model
	* \param model to collect
	*/
	void collectModels(Model *model);
	/*!
	* \brief Collect models
	* \param models to collect
	*/
	void collectModels(std::vector<Model*> models);
	/*!
	* \brief Collect light
	* \param light to collect
	*/
	void collectLights(Light *light);
	/*!
	* \brief Collect lights
	* \param lights to collect
	*/
	void collectLights(std::vector<Light*> lights);

	/*!
	* \brief return model assigned of the index
	* \param index index of the model in the collected models
	* \return model assigned
	*/
	Model* getModelIndexed(int index);
	/*!
	* \brief return material assigned of the index
	* \param index index of the material in the collected materials
	* \return material assigned
	*/
	Material* getMaterialIndexed(int index);
	/*!
	* \brief verify if the texture's name is already present in vector
	* \param name of the texture
	* \return The texture if it's already there
	*/
	Texture* getTexture(const std::string name);
	/*!
	* \brief get the rendered collected nodes
	* \return the rendered collected nodes
	*/
	std::vector<Node*> * getRenderedCollectedNodes();

	std::vector<Node*> nodesRenderer;
	std::vector<Node*> nodesLightRenderer;
	std::vector<Model*> m_models;
	std::vector<Material*> m_materials;
	std::vector<Texture*> m_textures;
	std::vector<Light*> m_lights;
};

#endif