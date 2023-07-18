#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	tempUpdate();
}

float Model::getCurrentTemp()
{
	return DEFRcurrentTemperatureLeft;
}

void Model::tempUpdate()
{
	modelListener->tempUpdate();
}
