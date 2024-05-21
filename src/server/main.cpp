#include <cstddef>
#include <cstdlib>
#include <iostream>

#include <sdk/LogManager.h>

/**
 * The main function logs a message, assigns a value to a variable using a compound statement, and then
 * returns success.
 * 
 * @param  The `int main(int, char **)` function is the entry point of a C or C++ program. It takes two
 * parameters: an integer representing the number of command line arguments passed to the program, and
 * an array of strings representing those command line arguments.
 * @param  The `int main(int, char **)` function is the entry point of a C or C++ program. It takes two
 * parameters: an integer representing the number of command-line arguments passed to the program, and
 * an array of strings representing those arguments.
 * 
 * @return EXIT_SUCCESS
 */
int main(int, char **)
{
    sdk_log_manager_info("Running server app");

    ({int id = 0; id = 3;});

    return EXIT_SUCCESS;
}
