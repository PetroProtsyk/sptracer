#include <windows.h>
#include <sstream>
#include "App.h"
#include "Log.h"

int main(int argc, char **argv)
{
	sptracer::Log::Info("SPTracer started");

	if (argc != 2)
	{
		// show help message
		std::ostringstream oss;
		oss << "Model file was not specified, default model will be used." << std::endl
		   << "Usage:" << std::endl
		   << "sptracer model_file.mdla";
		sptracer::Log::Info(oss.str());
	}

	// model file
	std::string fileName = argc == 2 ? argv[1] : "box.mdla";
	sptracer::Log::Info("Model file: " + fileName);

	// create application
	App app(fileName, 500, 500);
	
	// check that application is initialized
	if (!app.initialized())
	{
		return 1;
	}

	// run the application
	return app.Run();
}