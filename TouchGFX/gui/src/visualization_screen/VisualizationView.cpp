#include <gui/visualization_screen/VisualizationView.hpp>
#include <touchgfx/utils.hpp>

//#include "string.h"
#include "stdio.h"

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

void VisualizationView::tempUpdateView()
{
	Unicode::snprintfFloat(ValueDefrosterT1Buffer, sizeof(ValueDefrosterT1Buffer), "%.2f", Temp);
	ValueDefrosterT1.invalidate();

}
