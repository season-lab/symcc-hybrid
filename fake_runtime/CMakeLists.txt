# This file is part of SymCC.
#
# SymCC is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# SymCC is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# SymCC. If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.5)
project(SymRuntime)

set(CMAKE_CXX_FLAGS "-O2 ${CMAKE_CXX_FLAGS} \
-Wredundant-decls -Wcast-align \
-Wmissing-include-dirs -Wswitch-default \
-Winvalid-pch -Wredundant-decls -Wformat=2 \
-Wno-​unused-parameter")

# Place the final product in the top-level output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# There is list(TRANSFORM ... PREPEND ...), but it's not available before CMake 3.12.
set(SHARED_RUNTIME_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/RuntimeCommon.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/LibcWrappers.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Shadow.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GarbageCollection.cpp)

add_subdirectory(qsym_backend)
