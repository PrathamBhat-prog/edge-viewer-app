cmake_minimum_required(VERSION 3.22.1)

project("edgeviewer")

# Provide the include directory for OpenCV headers
include_directories("D:/OpenCV-android-sdk/sdk/native/jni/include")

# Add our native library
add_library(native-lib SHARED native-lib.cpp)

# Find the Android logging library
find_library(log-lib log)

# Link all necessary libraries to our native-lib
target_link_libraries(
        native-lib
        # Explicitly link the pre-built OpenCV shared library
        "D:/OpenCV-android-sdk/sdk/native/libs/${ANDROID_ABI}/libopencv_java4.so"
        # Force the link against the C++ shared library to resolve symbols
        c++_shared
        ${log-lib}
)
