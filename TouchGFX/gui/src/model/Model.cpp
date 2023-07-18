#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>




Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	tempUpdateModel();

}

float Model::getCurrentTemp()
{
	return DEFRcurrentTemperatureLeft;
}

void Model::tempUpdateModel()
{
	modelListener->tempUpdatePresenter();
}
