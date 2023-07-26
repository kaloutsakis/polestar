#ifndef UV_ILOGMANAGER_H /*{*/
#define UV_ILOGMANAGER_H

#ifdef __cplusplus /*{*/
    #define UV_API extern "C"
#else /*} __cplusplus*/
    #define UV_API extern
#endif /*} __cplusplus*/

UV_API void uv_log_manager_welcome();
UV_API void uv_log_manager_goodbye();
UV_API void uv_log_manager_info(const char *format, ...);
UV_API void uv_log_manager_warn(const char *format, ...);

#endif /*} UV_ILOGMANAGER_H*/