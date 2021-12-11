#include <string>
#include <vector>

// Readings structure holding type of sensor, value of sensor, and timestamp
struct Readings {
    std::string type;
    double value;
    std::time_t timestamp;
};
// vector to store the readings in
std::vector<Readings> sensor_data;

// Frequency structure holding the string frequency which is passed through command line arguments via the user
struct Frequency {
    std::string frequency;
};

// usage function: Prints the error message 
void usage() {
    std::cerr << "Program usage: ./a.out -f <parameters> " << std::endl;
    std::cerr << "The options can be: \n";
    std::cerr << "                  -h      prints this usage statement.\n";
    std::cerr << "                  -f      <frequency> controls the speed (seconds) in which to gather the sensor reading.\n";
    exit(-1);
}

// parseCommandLineArguments: takes the command line arguments entered during execution 
void parseCommandlineArguments(const int argc, const char** argv, Frequency &config) {

    if (argc <= 1)                                                                      // if the number of arguments passed is less than 1 then call usage function
        usage();
    
    for (int i = 1; i < argc; ++i) {                                                    // for loop through the aruments entered and store the argument as i
        std::string argument(argv[i]);

        if (argument.compare("-h") == 0)                                                // if the argument entered is -h; call the usage function
            usage();
        else if (argument.compare("-f") == 0) {                                         // else if the argument enetered is -f;
            if (i == argc -1)                                                           // if the argument value is incorrect; call the usage funcion
                usage();
                config.frequency = argv[i += 1];                                        // set the frequency using the argv entered alongside the parameter
        }
        else {                                                                          // else if all this fails, print an error message and the command line command entered
            std::cerr << " Invalid option provided! " << argv[i] << std::endl;
        }
    }
}