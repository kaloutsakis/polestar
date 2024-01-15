#include <iostream>
#include <cstdarg>
#include <spdlog/spdlog.h>
#include "ILogManager.h"

/* `UV_API void uv_log_manager_welcome()` is a function that is part of the `uv_log_manager` module. It
is responsible for printing a welcome message to the console. */
UV_API void uv_log_manager_welcome()
{
    using namespace spdlog;

    info("libuv demo application");
}

/* `UV_API void uv_log_manager_goodbye()` is a function that is part of the `uv_log_manager` module. It
is responsible for printing a goodbye message to the console. */
UV_API void uv_log_manager_goodbye()
{
    using namespace spdlog;

    info("libuv demo application is exiting");
}

/* The function `UV_API void uv_log_manager_info(const char *format, ...)` is a variadic function that
takes a format string and additional arguments. It is responsible for logging an informational
message to the console using the `spdlog` library. */
UV_API void uv_log_manager_info(const char *format, ...)
{
    char msg[4026] = {'\0'};

    {
        va_list args;
        va_start(args, format);
        vsnprintf(msg, 4025, format, args);
        va_end(args);
    }
    
    {
        using namespace spdlog;
        
        static const char prefix[] = "uv_log_manager";
        
        info("{} | {}", prefix, msg);
    }
}

/* The function `UV_API void uv_log_manager_warn(const char *format, ...)` is a variadic function that
takes a format string and additional arguments. It is responsible for logging a warning message to
the console using the `spdlog` library. The function uses the `vsnprintf` function to format the
message string with the provided arguments, and then uses the `spdlog::warn` function to log the
formatted message with a prefix indicating that it is coming from the `uv_log_manager` module. */
UV_API void uv_log_manager_warn(const char *format, ...)
{
    char msg[4026] = {'\0'};

    {
        va_list args;
        va_start(args, format);
        vsnprintf(msg, 4025, format, args);
        va_end(args);
    }
    
    {
        using namespace spdlog;
        
        static const char prefix[] = "uv_log_manager";
        
        warn("{} | {}", prefix, msg);
    }
}
