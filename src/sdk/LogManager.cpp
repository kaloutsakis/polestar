#include <iostream>
#include <cstdarg>
#include <spdlog/spdlog.h>
#include "LogManager.h"

SDK_API void sdk_log_manager_welcome()
{
    using namespace spdlog;

    info("libuv demo application");
}

SDK_API void sdk_log_manager_goodbye()
{
    using namespace spdlog;

    info("libuv demo application is exiting");
}

SDK_API void sdk_log_manager_info(const char *format, ...)
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
        
        static const char prefix[] = "sdk_log_manager";
        
        info("{} | {}", prefix, msg);
    }
}

SDK_API void sdk_log_manager_warn(const char *format, ...)
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
        
        static const char prefix[] = "sdk_log_manager";
        
        warn("{} | {}", prefix, msg);
    }
}
