#ifndef VISUALISATIONVIEW_HPP
#define VISUALISATIONVIEW_HPP

#include <gui_generated/visualisation_screen/VisualisationViewBase.hpp>
#include <gui/visualisation_screen/VisualisationPresenter.hpp>

class VisualisationView : public VisualisationViewBase
{
public:
    VisualisationView();
    virtual ~VisualisationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // VISUALISATIONVIEW_HPP
