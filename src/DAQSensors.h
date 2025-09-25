#ifndef CMBTL_DAQ_SENSORS_H
#define CMBTL_DAQ_SENSORS_H

#include "SensorInfo.h"
#include "SensorData.h"
#include <tuple>

#include "Sensors/sec.h"
#include "Sensors/microsec.h"

#include "Sensors/RPM_Sensor.h"
#include "Sensors/Analog_Sensor.h"
#include "Sensors/Linear_Analog_Sensor.h"

#include "Sensors/teensy_temp.h"

using std::array;
namespace cmbtl {
    //--------------- Define Sensor Indexes ----------------------------------------------------
    enum SensorIndex {
        SEC,
        MICRO_SEC,
        RPM1,
        RPM2,
        RPM3,
        RPM4,
        BrakePressure,
        LDS,
        Analog3,
        Analog4,
        TEENSY_TEMP
    };

    // Define RPM Sensors
    std::string RPM1GetName() { return "rpm1"; }
    std::string RPM2GetName() { return "rpm2"; }
    std::string RPM3GetName() { return "rpm3"; }
    std::string RPM4GetName() { return "rpm4"; }

    using RPM1_SENSOR_INFO = cmbtl::rpm_sensor::RPM_SENSOR<RPM1GetName>;
    using RPM2_SENSOR_INFO = cmbtl::rpm_sensor::RPM_SENSOR<RPM2GetName>;
    using RPM3_SENSOR_INFO = cmbtl::rpm_sensor::RPM_SENSOR<RPM3GetName>;
    using RPM4_SENSOR_INFO = cmbtl::rpm_sensor::RPM_SENSOR<RPM4GetName>;

    // Define Analog Sensors
    std::string BrakePressureGetName() { return "BrakePressure"; }
    std::string LDSGetName() { return "LDS"; }
    std::string Analog3GetName() { return "analog3"; }
    std::string Analog4GetName() { return "analog4"; }

    using BrakePressure_SENSOR_INFO = cmbtl::linear_analog_sensor::Linear_Analog_Sensor<BrakePressureGetName>;
    using LDS_SENSOR_INFO = cmbtl::linear_analog_sensor::Linear_Analog_Sensor<LDSGetName>;
    using ANALOG3_SENSOR_INFO = cmbtl::analog_sensor::ANALOG_SENSOR<Analog3GetName>;
    using ANALOG4_SENSOR_INFO = cmbtl::analog_sensor::ANALOG_SENSOR<Analog4GetName>;
    

    // The order that the sensor appear in the enum and this tuple MUST MUST BE THE SAME
    using SensorInfoTuple = std::tuple<
    cmbtl::sec::SEC_SENSOR_INFO,
    cmbtl::microsec::MICRO_SEC_SENSOR_INFO,
    RPM1_SENSOR_INFO,
    RPM2_SENSOR_INFO,
    RPM3_SENSOR_INFO,
    RPM4_SENSOR_INFO,
    BrakePressure_SENSOR_INFO,
    LDS_SENSOR_INFO,
    ANALOG3_SENSOR_INFO,
    ANALOG4_SENSOR_INFO,
    cmbtl::teensy_temp::TEENSY_TEMP_SENSOR_INFO
    >;

    using DAQSensorDataType = SensorData<SensorInfoTuple>;

}
#endif