
#
# Copyright (C) The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.4.1)


set(lib_dir ${CMAKE_CURRENT_SOURCE_DIR}/../../../jniLibs/)

add_library(zmq STATIC IMPORTED)
set_target_properties(zmq PROPERTIES IMPORTED_LOCATION
    ${lib_dir}/zmq/lib/${ANDROID_ABI}/libzmq.a)

add_library(wallet STATIC IMPORTED)
set_target_properties(wallet PROPERTIES IMPORTED_LOCATION
        ${lib_dir}/wallet_ffi/lib/${ANDROID_ABI}/libwallet_ffi.a
        IMPORTED_LINK_INTERFACE_LIBRARIES zmq)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")


add_library(combined SHARED
            combined.cpp)

target_include_directories(combined PRIVATE
                           ${lib_dir}/)

target_link_libraries(combined
                      android
                      wallet)