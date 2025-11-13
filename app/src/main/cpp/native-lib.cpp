#include <jni.h>
#include <string>
#include <android/log.h>
#include <vector>

// OpenCV includes
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#define LOG_TAG "NativeLib"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_edgeviewer_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    LOGI("JNI function called successfully!");
    std::string hello = "Hello from C++ (JNI is working!)";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jbyteArray JNICALL
Java_com_example_edgeviewer_MainActivity_processFrame(
        JNIEnv *env,
        jobject /* this */,
        jbyteArray input,
        jint width,
        jint height) {

    // 1. Get a pointer to the raw pixel data from the jbyteArray.
    jbyte *input_bytes = env->GetByteArrayElements(input, NULL);
    if (input_bytes == NULL) {
        LOGI("Error getting byte array elements");
        return NULL;
    }

    // 2. Create a cv::Mat that wraps the input data (no copy).
    // The format CV_8UC4 corresponds to ARGB_8888.
    cv::Mat frame(height, width, CV_8UC4, (unsigned char *)input_bytes);

    // 3. Duplicate the Mat to have a separate, modifiable copy.
    cv::Mat img = frame.clone();

    // 4. IMPORTANT: Release the JNI byte array elements to avoid memory leaks.
    env->ReleaseByteArrayElements(input, input_bytes, 0);

    // 5. Convert the processed cv::Mat (img) back to a jbyteArray.

    // Get the total number of bytes in the Mat.
    jsize output_size = img.total() * img.elemSize();

    // Create a new jbyteArray to hold the output pixels.
    jbyteArray output = env->NewByteArray(output_size);
    if (output == NULL) {
        LOGI("Error creating new byte array");
        return NULL;
    }

    // Get a pointer to the raw data of the Mat.
    unsigned char *output_bytes = img.data;

    // Copy the pixel data from the Mat to the new jbyteArray.
    env->SetByteArrayRegion(output, 0, output_size, (jbyte *)output_bytes);

    // 6. Return the new jbyteArray to Kotlin.
    return output;
}
