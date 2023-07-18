#include <gui/visualization_screen/VisualizationView.hpp>

#include "string.h"
float const Temp = 36/8;

VisualizationView::VisualizationView()
{

}

void VisualizationView::setupScreen()
{
    VisualizationViewBase::setupScreen();
}

void VisualizationView::tearDownScreen()
{
    VisualizationViewBase::tearDownScreen();
}

void VisualizationView::tempUpdate()
{
//	Unicode::snprintfFloat(ValueDefrosterT1, sizeof(ValueDefrosterT1), "%.2f", Temp);
	ValueDefrosterT1.invalidate();
}
