cmake_minimum_required(VERSION 3.22)
project(MyDaw VERSION 0.1.0)

add_subdirectory(../JUCE JUCE)

juce_add_gui_app(MyDaw
    PRODUCT_NAME "MyDaw")

target_sources(MyDaw PRIVATE
    Source/Main.cpp)

juce_generate_juce_header(MyDaw)

target_compile_definitions(MyDaw PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:MyDaw,JUCE_PRODUCT_NAME>"
    JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:MyDaw,JUCE_VERSION>")

target_link_libraries(MyDaw PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
    juce::juce_gui_extra)