
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

#define RETURN(status) \
    return uv_log_manager_goodbye(), (status)

#define RETURN2(level, status, format, ...) \
    return uv_log_manager_ ## level(format, ##__VA_ARGS__), (status)

void wait_for_a_while(uv_idle_t* handle) {
    static uint64_t counter = 0;

    if (!(counter % 100000))
        uv_log_manager_info("counter = %0.7llu", counter);
    if (counter++ >= 1000000)
        uv_idle_stop(handle);
}

int main(int argc, const char *argv[])
{
    uv_log_manager_welcome();

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