#include <jni.h>
#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/android_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>

extern "C" JNIEXPORT void JNICALL
Java_steve_cho_spdlogsample_MainActivity_logTest(JNIEnv *env, jobject ){

    auto android_logger = spdlog::android_logger_mt("android", "SPDLOG");
    //로그레벨 지정
    android_logger->set_level(spdlog::level::trace);
    //로그테스트
    android_logger->info("INFO");
    android_logger->debug("DEBUG");
    android_logger->error("ERORR");
    // change log pattern
    android_logger->set_pattern("[%T.%e] [%n] [%l] %v");
    android_logger->debug("AFTER PATTERN SET");

    //5mb size max and 10 rotated files
    auto rotating_logger = spdlog::rotating_logger_mt("FILE_LOG", "/sdcard/cplus_log.txt", 1048576 * 5, 10);
    //specify the log level
    rotating_logger->set_level(spdlog::level::debug);
    rotating_logger->info("INFO_INFO");
    rotating_logger->debug("DEBUG");
    rotating_logger->error("ERROR");
    //call the flush method to record the log results in the file
    rotating_logger->flush();
}
