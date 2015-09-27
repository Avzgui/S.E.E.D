#include <DefaultMaterial/DefaultMaterial.hpp>

DefaultMaterial::DefaultMaterial(const aiMaterial *material, Camera *cam, const std::string n, unsigned int *flag) : Material(material, cam, n, flag)
{
	this->init();
}
DefaultMaterial::DefaultMaterial(Camera *cam, const std::string n, unsigned int *flag) : Material(cam, n, "C:/Users/jeremy/Source/Repos/S.E.E.D/seed-framework/ressources/Materials/DefaultMaterial/Shaders", flag)
{
	this->init();
}

void DefaultMaterial::init()
{
	this->compl.ambiant = 0.1;
	this->compl.diffuse = 0.5;
	this->compl.specular = 0.4;

	this->M = glm::mat4(1.0);
	//this->M = glm::translate(M, glm::vec3(1.0, 0.0, 0.0));

	// Get a handle for our "MVP" uniform.
	// Only at initialisation time.
	this->MVPID = glGetUniformLocation(programID, "MVP");
	this->VID = glGetUniformLocation(programID, "V");
	this->MID = glGetUniformLocation(programID, "M");
	this->NMID = glGetUniformLocation(programID, "Normal_Matrix");
	this->INVERSEVID = glGetUniformLocation(programID, "V_inverse");
	this->compl.ambiantID = glGetUniformLocation(programID, "light.ambiant");
	this->compl.diffuseID = glGetUniformLocation(programID, "light.diffuse");
	this->compl.specularID = glGetUniformLocation(programID, "light.specular");
}

DefaultMaterial::~DefaultMaterial()
{
}

void DefaultMaterial::render(Model *model)
{
	this->M *= glm::rotate(0.005f, glm::vec3(0, 1, 0));
	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	this->MVP = camera->getProjectionMatrix() * camera->getViewMatrix() * this->M;
	this->V = camera->getViewMatrix();
	this->V_inverse = glm::inverse(this->camera->getViewMatrix());
	this->Normal_Matrix = glm::transpose(glm::inverse(this->M));
	//set the uniform variable MVP
	glUniformMatrix4fv(this->MVPID, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(this->VID, 1, GL_FALSE, &V[0][0]);
	glUniformMatrix4fv(this->MID, 1, GL_FALSE, &M[0][0]);
	glUniformMatrix4fv(this->INVERSEVID, 1, GL_FALSE, &V_inverse[0][0]);
	glUniformMatrix4fv(this->NMID, 1, GL_FALSE, &Normal_Matrix[0][0]);
	glUniform1fv(this->compl.ambiantID, 1, &(compl.ambiant));
	glUniform1fv(this->compl.diffuseID, 1, &(compl.diffuse));
	glUniform1fv(this->compl.specularID, 1, &(compl.specular));

	int i = 0;

	//Enable culling triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);



	int nbTextures = this->textures.size();
	//active and bind textures
	for (i = 0; i < nbTextures; i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		this->textures[i]->bind();
	}
	//render model
	model->render();

	//release textures
	for (i = 0; i < nbTextures; i++)
	{
		this->textures[i]->release();
	}
}