#pragma once

#include <JuceHeader.h>

//==============================================================================
// This is basically a sawtooth wave generator - maps a value that bounces between
// 0.0 and 1.0 at a random speed
struct BouncingNumber
{
    BouncingNumber()
        : speed (0.0004 + 0.0007 * Random::getSystemRandom().nextDouble()),
          phase (Random::getSystemRandom().nextDouble())
    {
    }

    float getValue() const
    {
        double v = fmod (phase + speed * Time::getMillisecondCounterHiRes(), 2.0);
        return (float) (v >= 1.0 ? (2.0 - v) : v);
    }

protected:
    double speed, phase;
};

struct SlowerBouncingNumber  : public BouncingNumber
{
    SlowerBouncingNumber()
    {
        speed *= 0.3;
    }
};


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   :  public Component, private OpenGLRenderer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    Rectangle<int> rectArea;
    
    // moving rectangle coordinates
    SlowerBouncingNumber x;
    int y = 0;
    
    void newOpenGLContextCreated() override;
    void openGLContextClosing() override;
    void renderOpenGL() override;
    
    OpenGLContext openGLContext;
    
    void drawAnimation(float);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};


