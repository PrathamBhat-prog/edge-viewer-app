Edge Viewer App (Android + OpenCV + JNI)

A lightweight Android application that captures an image from the camera and generates an edge-detected version of the image using OpenCV (C++), JNI, and the Camera2 API.
This project demonstrates native image processing on Android and a complete pipeline from camera frame → bitmap → JNI → OpenCV → processed output.

Features

• Live Camera Preview
Full-screen camera feed using TextureView.

• Capture Image
Captures a frame from the TextureView and converts it into a Bitmap.

• Native Edge Detection (OpenCV + C++)
Processing done entirely in the native layer using OpenCV (Canny / Sobel).

• Display Processed Image
The processed result is shown in an ImageView.

• Retake Function
User can return to live camera preview after viewing the output.

Tech Stack

Android:

Kotlin

Camera2 API

TextureView

Native Layer:

C++

OpenCV Android SDK

JNI

CMake

Build Tools:

Gradle

Android Studio

How It Works

App starts and shows live camera preview

User taps Capture

Bitmap is converted to ByteArray

ByteArray is sent to native C++ via JNI

OpenCV performs edge detection

Native code returns processed RGBA frame

App displays the processed image

User taps Retake to restart the preview

Native Image Processing (Summary)

The JNI function processFrame(...) performs:

ByteArray → cv::Mat conversion

Grayscale conversion

Edge detection (Canny/Sobel)

cv::Mat → ByteArray

Sends processed data back to Android

Build & Run Guide

Option A — Run via Android Studio:

Open the project

Connect an Android device

Press Run

Option B — Install Debug APK:

Build → Build APK(s)

Find the APK at:
app/build/outputs/apk/debug/app-debug.apk

This debug APK is acceptable for assignment submission.

Simplified Project Structure

app/
src/main/java/com/example/edgeviewer/MainActivity.kt
src/main/cpp/native-lib.cpp
src/main/cpp/CMakeLists.txt
src/main/res/layout/activity_main.xml
build.gradle.kts

Tested On:

Samsung M33

Android API 24+

Architectures: arm64-v8a, armeabi-v7a

Notes for Reviewer

Demonstrates full native OpenCV integration

Includes camera capture → native processing → display

Retake implementation supports continuous use

Debug build is used for submission (Release not required)

License

This repository is part of a technical assignment submission.
All code is for demonstration purposes only.