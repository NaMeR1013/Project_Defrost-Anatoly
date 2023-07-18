#include <gui/visualization_screen/VisualizationView.hpp>
#include <gui/visualization_screen/VisualizationPresenter.hpp>

VisualizationPresenter::VisualizationPresenter(VisualizationView& v)
    : view(v)
{

}

void VisualizationPresenter::activate()
{

}

void VisualizationPresenter::deactivate()
{

}

void VisualizationPresenter::tempUpdatePresenter()
{
	view.tempUpdateView();
}

