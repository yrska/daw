#include <JuceHeader.h>

//==============================================================================
class MainComponent : public juce::Component
{
public:
    MainComponent()
    {
        setSize(600, 400);
    }

    void paint(juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::darkslategrey);
        g.setColour(juce::Colours::white);
        g.setFont(24.0f);
        g.drawText("MyDaw - toolchain works!", getLocalBounds(),
            juce::Justification::centred, true);
    }
};

//==============================================================================
class MyDawApplication : public juce::JUCEApplication
{
public:
    MyDawApplication() {}

    const juce::String getApplicationName() override { return "MyDaw"; }
    const juce::String getApplicationVersion() override { return "0.1.0"; }

    void initialise(const juce::String&) override
    {
        mainWindow.reset(new MainWindow(getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow = nullptr;
    }

    //==============================================================================
    class MainWindow : public juce::DocumentWindow
    {
    public:
        MainWindow(juce::String name)
            : DocumentWindow(name,
                juce::Desktop::getInstance().getDefaultLookAndFeel()
                .findColour(juce::ResizableWindow::backgroundColourId),
                DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(new MainComponent(), true);
            centreWithSize(getWidth(), getHeight());
            setVisible(true);
        }

        void closeButtonPressed() override
        {
            juce::JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
START_JUCE_APPLICATION(MyDawApplication)