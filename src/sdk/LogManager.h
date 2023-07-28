#ifndef SDK_LOGMANAGER_H /*{*/
#define SDK_LOGMANAGER_H

#ifndef __cplusplus /*{*/
    #define SDK_API extern "C"
#else /*} __cplusplus*/
    #define SDK_API extern
#endif /*} __cplusplus*/

SDK_API void sdk_log_manager_goodbye();
SDK_API void sdk_log_manager_welcome();
SDK_API void sdk_log_manager_info(const char *format, ...);
SDK_API void sdk_log_manager_warn(const char *format, ...);

#endif /*} SDK_LOGMANAGER_H*/