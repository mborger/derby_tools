# Copyright 2012 Matthew Borger
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

CC = g++
CFLAGS = -g -std=c++0x
PKGC = `pkg-config --cflags gtkmm-3.0`
PKGL = `pkg-config --libs gtkmm-3.0` -lboost_regex

all: main

main: src/main.cpp src/DerbyTools.h src/DerbyTools.cpp src/InputReader.h src/InputReader.cpp src/DerbyModel.h src/Team.h src/Team.cpp
	${CC} src/main.cpp src/DerbyTools.cpp src/InputReader.cpp src/Team.cpp -o main -g ${PKGC} ${PKGL}

main.o: src/main.cpp
	${CC} src/main.cpp -c ${CFLAGS} ${PKGC}

install-conf:
	install -m 644 xorg_config/12-barcode.conf /etc/X11/xorg.conf.d/

clean:
	rm -f main *.o

.phony: clean install-conf
