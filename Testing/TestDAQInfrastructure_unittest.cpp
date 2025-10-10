#include "SensorData.h"
#include "gtest/gtest.h"
#include "DAQSensors.h"
#include "DAQTestSensors.h"
#include "DAQPackets.h"
#include "Packets/PacketInstructions.h"
#include <iostream>

TEST(DAQTestJSONSerializationTest, DAQTestSerializeToJSON) {
    cmbtl::test::DAQTestSensorDataType testSensorData;
    std::cout << std::endl;
    std::cout << testSensorData.serializeDataToJSON();
    std::cout << std::endl;
}