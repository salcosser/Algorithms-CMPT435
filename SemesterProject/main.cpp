#include <iostream>
#include <string>
#include <algorithm>
#include "PooledTesting.h"

int main(int argc, char **argv)
{
    std::string type = std::string(argv[1]);

    if (type == "quick")
    {
        PooledTesting *pt = new PooledTesting();
        pt->testThePools(std::stod(argv[2]), std::stod(argv[3]));
        
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
                    std::cout << "What is your simulated percentage of positive cases as an integer (i.e. 3% would be 3)? or type 'quit' to exit" << std::endl;
                    std::string preProcessedPer;
                    std::getline(std::cin, preProcessedPer);
                    if (preProcessedPer.find("quit") != std::string::npos)
                    {
                        std::cout << "Goodbye." << std::endl;
                        running = false;
                        break;
                    }
                    else if ((preProcessedPer.find_first_not_of("0123456789") == std::string::npos))
                    {
                        if (std::stoi(preProcessedPer) <= 100)
                        {
                            pcPos = (std::stod(preProcessedPer) * .01);

                            PooledTesting *pt = new PooledTesting(); //actually doing the tests
                            pt->testThePools(sampSize, pcPos);

                            std::cout << "completed test of " << sampSize << " people with an overall positivity percentage of " << pcPos << "." << std::endl;

                            havePercent = true;
                        }
                        else
                        {
                            std::cout << "ERROR: Please only use positive integer numbers between 0 and 100 for percentages (i.e. 3% would be 3).\a" << std::endl;
                            std::cout << "--------------------------------------------------------" << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "ERROR: Please only use positive integer numbers between 0 and 100 for percentages (i.e. 3% would be 3).\a" << std::endl;
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
