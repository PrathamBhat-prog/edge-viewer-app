# Edge Viewer App (Android + OpenCV + JNI)

A lightweight Android application that captures an image from the camera and generates an **edge-detected version** of the image using **OpenCV (C++), JNI**, and **native image processing pipelines**.

This project demonstrates end-to-end integration of:

- Android Camera API (TextureView)
- Bitmap → ByteArray conversion
- JNI communication
- Native C++ image processing using OpenCV
- UI workflow with capture & retake functionality

---

## 📌 **Features**

### ✔ Live Camera Preview  
The app opens with a full-screen camera preview.

### ✔ Capture Button  
Takes a snapshot from the TextureView's camera preview.

### ✔ Native Edge Detection (C++)  
Captured image is processed using:
- OpenCV  
- Sobel/Canny edge detection  
- C++ native library via JNI

### ✔ Processed Image Rendering  
The edge-detected result is displayed on the screen.

### ✔ Retake Option  
After viewing the processed image, the user can return to the camera preview and capture another image.

---

## 🛠 **Tech Stack**

### **Frontend / Android**
- Kotlin  
- TextureView  
- Camera2 API  
- ConstraintLayout  

### **Native Layer**
- C++17  
- OpenCV Android SDK  
- JNI (Java Native Interface)

### **Build Tools**
- Gradle  
- CMake  
- Android Studio

---

## 🧠 **Architecture Overview**

