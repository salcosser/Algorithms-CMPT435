#include <iostream>
#include <string>
#include <algorithm>
#include "PooledTesting.h"

int main(int argc, char **argv)
{
    std::string type = std::string(argv[1]);
    bool readOut = false;
    if( argc == 5 && std::string(argv[4]) == "printAll"){
        readOut = true;
    }
    if (type == "quick")
    {
        PooledTesting *pt = new PooledTesting();
        pt->testThePools(std::stod(argv[2]), std::stod(argv[3]), readOut);
        
    }
    
    else if (type == "cli")
    {

    

        int sampSize = 0;
        double pcPos = 0;
        bool running = true;
      
        std::cout << "****************************************" << std::endl;
        std::cout << "POOLED TESTING SIMULATOR" << std::endl;
        std::cout << "Welcome to the Pooled Testing Simulator!" << std::endl;
        
        while (running)
        {
            bool havePercent = false;
            std::cout << "****************************************" << std::endl;
            std::cout << " either type 'run' follwed by a single space and your total case size, or type 'quit' to exit" << std::endl;
            std::cout << "Example: 'run 1000' or 'quit'" << std::endl;
            std::string command;

            std::getline(std::cin, command);
            if (command == "quit")
            {
                std::cout << "Goodbye." << std::endl;
                running = false;
            }
            else if (command.find("run") != std::string::npos && (command.substr(4).find_first_not_of("0123456789") == std::string::npos))
            {
                sampSize = std::stoi(command.substr(4));
                std::cout << sampSize << " Was your defined sample size." << std::endl;

                while (!havePercent)
                {
                    std::cout << "What is your simulated percentage of positive cases as a decimal number (i.e. 3% would be .03)? or type 'quit' to exit" << std::endl;
                    std::string preProcessedPer;
                    std::getline(std::cin, preProcessedPer);
                    if (preProcessedPer.find("quit") != std::string::npos)
                    {
                        std::cout << "Goodbye." << std::endl;
                        running = false;
                        break;
                    }
                    else if ((preProcessedPer.find_first_not_of("0123456789.") == std::string::npos))
                    {
                        if (std::stod(preProcessedPer) <= 1)
                        {
                            pcPos = std::stod(preProcessedPer);

                            PooledTesting *pt = new PooledTesting(); //actually doing the tests
                            pt->testThePools(sampSize, pcPos, true);

                            std::cout << "completed test of " << sampSize << " people with an overall positivity percentage of " << (pcPos * 100)<< "% ("<< pcPos <<")" << "." << std::endl;

                            havePercent = true;
                        }
                        else
                        {
                            std::cout << "ERROR: Please only use positive decimal numbers between 0 and 1 (i.e. 3% would be .03).\a" << std::endl;
                            std::cout << "--------------------------------------------------------" << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "ERROR: Please only use positive decimal numbers between 0 and 1 (i.e. 3% would be .03).\a" << std::endl;
                        std::cout << "--------------------------------------------------------" << std::endl;
                    }
                }
            }
            else if (running)
            {

                std::cout << "ERROR: Sorry, that command was not recognized.\a" << std::endl;
            }
        }
    }

    return 0;
}
