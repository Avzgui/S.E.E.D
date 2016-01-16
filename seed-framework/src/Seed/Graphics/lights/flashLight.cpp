//SEED INCLUDES
#include <Seed/Graphics/lights/flashLight.hpp>
#include <Seed/Graphics/engine/Constant.hpp>

FlashLight::FlashLight(const std::string &n, const glm::vec3 &pos, const glm::vec3 &dir, const glm::vec3 &K2, const glm::vec3 &c, const float &ang, const int &dist) : Light(n, c)
{
	this->position = pos;
	this->direction = dir;
	this->angle = ang;
	this->constant = Attenuation[0][distToAttenuation.at(dist)];
	this->linear = Attenuation[1][distToAttenuation.at(dist)];
	this->quadratic = Attenuation[2][distToAttenuation.at(dist)];
	this->K = K2;
}

FlashLight::~FlashLight()
{
}

glm::vec3 FlashLight::getAttenuation()
{
	return glm::vec3(this->constant, this->linear, this->quadratic);
}

glm::vec3 FlashLight::getDirection()
{
	return this->direction;
}

glm::vec3 FlashLight::getPosition()
{
	return this->position;
}

glm::vec3 FlashLight::getK()
{
	return this->K;
}