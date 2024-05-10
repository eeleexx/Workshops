///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Execute Callback
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void executeCallback(void (*callback)())` that takes a 
/// function pointer and executes the callback function.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void exampleCallback() {
    std::cout << "what did i just do" << "\n";
}

void executeCallback(void (*callback)()) {
    callback();
}

int main()
{

    executeCallback(exampleCallback);

    return 0;
}
