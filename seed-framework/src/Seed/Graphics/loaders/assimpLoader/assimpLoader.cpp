#include <Seed/Graphics/loaders/assimpLoader/assimpLoader.hpp>
#include <Seed/Graphics/engine/collector.hpp>
#include <Seed/Graphics/model/model.hpp>
#include <Seed/Graphics/node/objectNode.hpp>
#include <GL/glew.h>

AssimpLoader::AssimpLoader()
{

}

AssimpLoader::~AssimpLoader()
{

}

ObjectNode* AssimpLoader::importModelFromFile(const std::string path, Scene *scene, Collector *collector, const std::string name)
{
	Assimp::Importer importer;
	bool exist = false;

	//file exists?
	std::ifstream fichier(path);
	if (!fichier.fail())
	{
		exist = true;
		fichier.close();
	}
	else
	{
		std::cout << "ERROR LOADING MODEL : Couldn't open file: " << path << std::endl;
		return nullptr;
	}

	ObjectNode* node = nullptr;

	//if file exists
	if (exist)
	{
		//imports model in pScene, the model is triangulate, with tangents informations and merges same vertices
		//A REDEFINIR!!
		const aiScene *pScene = importer.ReadFile(path, aiProcessPreset_TargetRealtime_Fast);
		//if pScene exists, the mesh is assigning with node
		if (pScene)
		{
			if ((node = loadObjectInScene(pScene, path, scene, collector, name)) == NULL)
			{
				std::cout << "ERROR LOADING MODEL : error parsing " << path << std::endl << importer.GetErrorString() << std::endl;
				return nullptr;
			}
		}
		else
		{
			std::cout << "ERROR ASSIMP LOADING MODEL : Couln't import Mesh" << std::endl;
			return nullptr;
		}
	}
	return node;
}

ObjectNode* AssimpLoader::loadObjectInScene(const aiScene *pScene, const std::string path, Scene *scene, Collector *collector, const std::string name)
{
	int i = 0;
	//A MODIFIER PARSER LE FICHIER POUR SAVOIR LE NOM SINON DONNER UN NOM GENERIQUE
	//adding child's objectnode to the root objectnode
	ObjectNode *objectNode = new ObjectNode(scene, name);
	//set the root node like father node
	//node->setFather(this->rootNode);
	//set this node like son's node to the root node
	//this->rootNode->addChild(node);

	//load Meshes
	this->loadMeshes(pScene, collector, path);

	//load Materials
	//this->loadMaterials(pScene, name);

	//insert nodes
	this->insertRecurNode(pScene, pScene->mRootNode, objectNode, scene, collector);
	
	return objectNode;
}

void AssimpLoader::insertRecurNode(const aiScene *pScene, const aiNode *nodeFather, ObjectNode *father, Scene *scene, Collector *collector)
{
	int i = 0;
	//attribute address's meshe to the node if this is a leaf
	if (nodeFather->mNumMeshes == 1)
	{
		father->setModel(collector->getModelIndexed(nodeFather->mMeshes[0]));
		/*unsigned int indexMaterial = pScene->mMeshes[nodeFather->mMeshes[0]]->mMaterialIndex;
		if (indexMaterial >= 0)
		{
			father->setMaterial(this->m_materials[pScene->mMeshes[nodeFather->mMeshes[0]]->mMaterialIndex]);
		}*/
	}
	//recursive method for exploring children's nodes and do the same thing
	for (int i = 0; i < nodeFather->mNumChildren; i++)
	{
		ObjectNode *n;
		if (nodeFather->mChildren[i]->mName.C_Str() != "")
		{
			n = new ObjectNode(scene, nodeFather->mChildren[i]->mName.C_Str());
		}
		else
		{
			n = new ObjectNode(scene, father->getName() + "_" + std::to_string(i));
		}
		father->addChild(n);
		n->setFather(father);
		this->insertRecurNode(pScene, nodeFather->mChildren[i], n, scene, collector);
	}
}

void AssimpLoader::loadMeshes(const aiScene *pScene, Collector *collector, std::string path)
{
	//insert meshes
	for (int i = 0; i < pScene->mNumMeshes; i++)
	{
		Model *m = new Model(pScene->mMeshes[i], GL_STATIC_DRAW, path);
		collector->collectModels(m);
	}
}