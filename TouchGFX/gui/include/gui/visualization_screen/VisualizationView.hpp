#ifndef VISUALIZATIONVIEW_HPP
#define VISUALIZATIONVIEW_HPP

#include <gui_generated/visualization_screen/VisualizationViewBase.hpp>
#include <gui/visualization_screen/VisualizationPresenter.hpp>

class VisualizationView : public VisualizationViewBase
{
public:
    VisualizationView();
    virtual ~VisualizationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void tempUpdateView();
protected:
    float Temp = 36.67;

};

#endif // VISUALIZATIONVIEW_HPP
