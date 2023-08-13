/*****************************************************************//**
@file   entryPoint.h
@brief  Location in the code where the execution of the program begins.

@author Joseph-Cossins-Smith
@date   July 2023
 *********************************************************************/
#pragma once

#include "core/application.h"

// Declare an external function prototype for starting the application from the Engine namespace.
extern Engine::Application* Engine::startApplication();

// Entry point of the program.
int main(int argc, char** argv)
{
	// Call the startApplication function from the Engine namespace to create the application instance.
	auto application = Engine::startApplication();

	// Run the application.
	application->run();

	// Clean up and delete the application instance.
	delete application;

	// Return 0 to indicate successful execution.
	return 0;
}

