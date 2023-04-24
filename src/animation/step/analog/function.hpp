/// \file animation/step/analog/function.hpp
/// \brief Defines the animation::step::analog::function class.
#ifndef ANIMATION___STEP___ANALOG___FUNCTION_H
#define ANIMATION___STEP___ANALOG___FUNCTION_H

// animation
#include <animation/step/step.hpp>

namespace animation {
namespace step {
/// \brief Contains all code for analog animation steps.
namespace analog {

/// \brief An animation step that sets an analog output pin according to a user defined function.
class function
    : public animation::step::step
{
public:
    // CONSTRUCTORS
    /// \brief Creates a new analog function step.
    /// \param pin The analog output pin to animate.
    function(uint8_t pin);

    // CONTROL
    void start() override;

    // RUN
    bool run_once() override;

protected:
    // FUNCTION
    /// \brief The function that determines the output level as a function of time.
    /// \param time The current time since the step started, in seconds.
    /// \param complete OUTPUT Indicates if the function has completed.
    virtual uint8_t level(float time, bool& complete) = 0;

private:
    // IO
    /// \brief The analog output pin to animate.
    const uint8_t m_pin;
    
    // TIME
    /// \brief The timestamp that the step was started at, in milliseconds.
    uint32_t m_start_time;
};

}}}

#endif