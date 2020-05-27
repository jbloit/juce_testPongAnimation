/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    
    setOpaque (true);

    openGLContext.setRenderer (this);
    openGLContext.attachTo (*this);
    openGLContext.setContinuousRepainting (true);
    
    setSize (800, 600);
    setFramesPerSecond (60); // This sets the frequency of the update calls.
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::update()
{
    // This function is called at the frequency specified by the setFramesPerSecond() call
    // in the constructor. You can use it to update counters, animate values, etc.

//    rectArea.setX(x);
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
}

void MainComponent::resized()
{
    y = getHeight()/2;
}

void MainComponent::newOpenGLContextCreated()
{
    
}

void MainComponent::openGLContextClosing()
{
    
}

void MainComponent::renderOpenGL()
{
    jassert (OpenGLHelpers::isContextActive());

    auto desktopScale = (float) openGLContext.getRenderingScale();

    OpenGLHelpers::clear (Colours::blue);


    // First draw our background graphics to demonstrate the OpenGLGraphicsContext class
    drawBackground2DStuff (desktopScale);
}


void MainComponent::drawBackground2DStuff (float desktopScale)
{
    // Create an OpenGLGraphicsContext that will draw into this GL window..
    std::unique_ptr<LowLevelGraphicsContext> glRenderer (createOpenGLGraphicsContext (openGLContext,
                                                                                      roundToInt (desktopScale * getWidth()),
                                                                                      roundToInt (desktopScale * getHeight())));

    if (glRenderer.get() != nullptr)
    {
        Graphics g (*glRenderer);
        g.addTransform (AffineTransform::scale (desktopScale));


        // This stuff just creates a spinning star shape and fills it..
        Path p;
        p.addRectangle(getWidth() * x.getValue(), y, 100, 100);
        g.setColour(Colours::orange);
        g.fillPath (p);
    }
}
