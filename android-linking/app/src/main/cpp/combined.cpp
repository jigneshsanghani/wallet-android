/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <cstring>
#include <jni.h>
#include <cinttypes>
#include <android/log.h>
#include <wallet.h>
#include <string>
#include <math.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_applinking_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    TariPrivateKey *pk = private_key_generate();
    ByteVector *bytes = private_key_get_bytes(pk);
    unsigned int bytes_length = byte_vector_get_length(bytes);
    std::string s = std::string("");
    for (int i = 0; i <= bytes_length; i++)
    {
        unsigned int byte = byte_vector_get_at(bytes,i);
        s += static_cast<char>(trunc(byte/2)); //should be converted to hex, div by 2 to ensure utf8 valid
    }

    return env->NewStringUTF(s.c_str());
}
