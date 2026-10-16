all: ingenuity_mimic_project
ingenuity_mimic_project: 	arduinoSensors.h \
							arduinoSensors.cpp \
							marsTime.h \
							marsTime.cpp \
							dataPacketWriting.h \
							dataPacketWriting.cpp 



	g++ -Wall -g -std=c++17 -pedantic \
		arduinoSensors.cpp \
		marsTime.cpp \
		dataPacketWriting.cpp