#include <animation/step/analog/level.hpp>

using namespace animation::step::analog;

// CONSTRUCTORS
level::level(uint8_t pin, uint8_t level)
    : m_pin(pin),
      m_level(level)
{}

// CONTROL
void level::start()
{
    // No start routine required.
}

// RUN
bool level::run_once()
{
    // Set the analog level.
    analogWrite(level::m_pin, level::m_level);

    // Indicate step complete.
    return true;
}