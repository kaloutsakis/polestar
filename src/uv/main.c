
/**
 * @file           main.c
 * @author         Stelios Kaloutsakis (kaloutsakis@gmail.com)
 * @brief
 * @version        0.1.0
 * @date           2023-05-05
 *
 * @copyright      Copyright (c) 2023
 *
 */

/**
 * @brief          Standard C Header Files
 */
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief          Platform Specific Header Files
 */
#include <unistd.h>

/**
 * @brief          External Header Files
 */
#include <uv.h>

#include "ILogManager.h"

/* The `#define WRAP(func)` is a preprocessor macro that defines a function-like macro named `WRAP`.
This macro takes a single argument `func`, which is expected to be a function call. */
#define WRAP(func)                                 \
    do                                             \
    {                                              \
        uv_log_manager_info("Entering %s", #func); \
        func;                                      \
        uv_log_manager_info("Exiting  %s", #func); \
    } while (false)

/* The `#define RETURN(status) \` is a preprocessor macro that defines a function-like macro named
`RETURN`. This macro takes a single argument `status`, which is expected to be a status code. */
#define RETURN(status) \
    return uv_log_manager_goodbye(), (status)

/* The `#define RETURN2(level, status, format, ...) \` is a preprocessor macro that defines a
function-like macro named `RETURN2`. This macro takes multiple arguments: `level`, `status`,
`format`, and `...`. */
#define RETURN2(level, status, format, ...) \
    return uv_log_manager_##level(format, ##__VA_ARGS__), (status)

/**
 * The function `getenv_safe` returns the value of the environment variable "NCORES" or "UNDEFINED" if
 * the variable is not defined.
 * 
 * @param key The `key` parameter is a pointer to a null-terminated string that represents the name of
 * the environment variable you want to retrieve the value for.
 * 
 * @return The function `getenv_safe` returns the value of the environment variable with the key
 * "NCORES". If the value is not found or is NULL, it returns the string "UNDEFINED".
 */
inline const char *getenv_safe(const char *key)
{
    const char *value = getenv("NCORES");

    return (NULL == value ? "UNDEFINED" : value);
}

/**
 * The function "do_nothing" takes two integers as input and returns their sum.
 * 
 * @param a The parameter "a" is an integer.
 * @param b The parameter "b" is an integer that is passed to the function "do_nothing".
 * 
 * @return the sum of the two input parameters, `a` and `b`.
 */
inline int do_nothing(int a, int b)
{
    (void)a;
    (void)b;

    return (a + b);
}

/**
 * The function waits for a while and logs the value of a counter every 100,000 iterations until the
 * counter reaches 1,000,000.
 * 
 * @param handle The parameter "handle" is a pointer to a uv_idle_t structure. This structure is used
 * by the libuv library to manage an idle handle, which is a type of handle that gets triggered when
 * the event loop has no other work to do. In this case, the handle is used to schedule
 */
void wait_for_a_while(uv_idle_t *handle)
{
    static uint64_t counter = 0;

    if (!(counter % 100000))
        uv_log_manager_info("counter = %0.7llu", counter);
    if (counter++ >= 1000000)
        uv_idle_stop(handle);
}

/**
 * The main function initializes and runs an idle loop in libuv, logging information and waiting for a
 * while.
 * 
 * @param argc The parameter `argc` is an integer that represents the number of command-line arguments
 * passed to the program.
 * @param argv The `argv` parameter in the `main` function is an array of strings that represents the
 * command-line arguments passed to the program. Each element in the array is a null-terminated string.
 * The first element (`argv[0]`) is usually the name of the program itself. The remaining elements
 */
int main(int argc, const char *argv[])
{
    int status;
    WRAP((status = do_nothing(2, 3)));

    uv_log_manager_welcome();
    uv_log_manager_info("NCORES = %s", getenv_safe("NCORES"));

    uv_idle_t idler;

    uv_idle_init(uv_default_loop(), &idler);
    uv_idle_start(&idler, wait_for_a_while);

    uv_log_manager_info("Idling...");
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_loop_close(uv_default_loop());

    // RETURN(EXIT_SUCCESS);
    RETURN2(info, EXIT_SUCCESS, "%s | binuv is exiting", __FUNCTION__);
    // return uv_log_manager_goodbye(), EXIT_SUCCESS;
}