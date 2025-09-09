#ifndef CMBTL_DAQ_SENSORS_H
#define CMBTL_DAQ_SENSORS_H

#include "SensorInfo.h"
#include "SensorData.h"
#include <tuple>

#include "Sensors/sec.h"
#include "Sensors/microsec.h"

#include "Sensors/RPM_Sensor.h"
#include "Sensors/Analog_Sensor.h"

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
        Analog1,
        Analog2,
        Analog3,
        Analog4
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
    std::string Analog1GetName() { return "analog1"; }
    std::string Analog2GetName() { return "analog2"; }
    std::string Analog3GetName() { return "analog3"; }
    std::string Analog4GetName() { return "analog4"; }

    using ANALOG1_SENSOR_INFO = cmbtl::analog_sensor::ANALOG_SENSOR<Analog1GetName>;
    using ANALOG2_SENSOR_INFO = cmbtl::analog_sensor::ANALOG_SENSOR<Analog2GetName>;
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
    ANALOG1_SENSOR_INFO,
    ANALOG2_SENSOR_INFO,
    ANALOG3_SENSOR_INFO,
    ANALOG4_SENSOR_INFO
    >;

    using DAQSensorDataType = SensorData<SensorInfoTuple>;

}
#endif