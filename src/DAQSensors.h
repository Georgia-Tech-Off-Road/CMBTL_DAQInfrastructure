#ifndef CMBTL_DAQ_SENSORS_H
#define CMBTL_DAQ_SENSORS_H

#include "SensorInfo.h"
#include "SensorData.h"
#include <tuple>

#include "Sensors/sec.h"
#include "Sensors/microsec.h"

#include "Sensors/RPM_Sensor.h"

using std::array;
namespace cmbtl {
    //--------------- Define Sensor Indexes ----------------------------------------------------
    enum SensorIndex {
        SEC,
        MICRO_SEC,
        RPM1,
        RPM2,
        RPM3,
        RPM4
    };

    std::string RPM1GetName() { return "rpm1";}
    std::string RPM2GetName() { return "rpm2";}
    std::string RPM3GetName() { return "rpm3";}
    std::string RPM4GetName() { return "rpm4";}

    // Define RPM Sensors
    using RPM1_SENSOR_INFO = cmbtl::rpm_sensor::RPM_SENSOR<RPM1GetName>;
    using RPM2_SENSOR_INFO = cmbtl::rpm_sensor::RPM_SENSOR<RPM2GetName>;
    using RPM3_SENSOR_INFO = cmbtl::rpm_sensor::RPM_SENSOR<RPM3GetName>;
    using RPM4_SENSOR_INFO = cmbtl::rpm_sensor::RPM_SENSOR<RPM4GetName>;

    // The order that the sensor appear in the enum and this tuple MUST MUST BE THE SAME
    using SensorInfoTuple = std::tuple<
    cmbtl::sec::SEC_SENSOR_INFO,
    cmbtl::microsec::MICRO_SEC_SENSOR_INFO,
    RPM1_SENSOR_INFO,
    RPM2_SENSOR_INFO,
    RPM3_SENSOR_INFO,
    RPM4_SENSOR_INFO
    >;

    using DAQSensorDataType = SensorData<SensorInfoTuple>;

}
#endif