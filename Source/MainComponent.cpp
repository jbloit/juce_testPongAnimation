#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    
    setOpaque (true);

    openGLContext.setRenderer (this);
    openGLContext.attachTo (*this);
    openGLContext.setContinuousRepainting (true);
    
    setSize (800, 600);
    
}

MainComponent::~MainComponent()
{
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
    drawAnimation (desktopScale);
}


void MainComponent::drawAnimation (float desktopScale)
{
    std::unique_ptr<LowLevelGraphicsContext> glRenderer (createOpenGLGraphicsContext (openGLContext,
                                                                                      roundToInt (desktopScale * getWidth()),
                                                                                      roundToInt (desktopScale * getHeight())));
    if (glRenderer.get() != nullptr)
    {
        Graphics g (*glRenderer);
        g.addTransform (AffineTransform::scale (desktopScale));

        Path p;
        p.addRectangle(getWidth() * x.getValue(), y, 100, 100);
        g.setColour(Colours::orange);
        g.fillPath (p);
    }
}
