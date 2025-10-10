#ifndef CMBTL_DAQ_TEST_SENSORS_H
#define CMBTL_DAQ_TEST_SENSORS_H

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
    namespace test {
        //--------------- Define Sensor Indexes ----------------------------------------------------
        enum SensorIndex {
            SEC,
            MICRO_SEC,
            RPM1,
            RPM2,
            RPM3,
            RPM4,
            BrakePressure,
            LDS1,
            LDS2,
            LDS3,
            LDS4,
            CVT_TEMP,
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

        std::string LDS1GetName() { return "LDS1"; }
        std::string LDS2GetName() { return "LDS2"; }
        std::string LDS3GetName() { return "LDS3"; }
        std::string LDS4GetName() { return "LDS4"; }

        std::string CVTTempGetName() {return "cvt_temp"; }

        std::string Analog3GetName() { return "analog3"; }
        std::string Analog4GetName() { return "analog4"; }

        using BrakePressure_SENSOR_INFO = cmbtl::linear_analog_sensor::Linear_Analog_Sensor<BrakePressureGetName>;

        using LDS1_SENSOR_INFO = cmbtl::linear_analog_sensor::Linear_Analog_Sensor<LDS1GetName>;
        using LDS2_SENSOR_INFO = cmbtl::linear_analog_sensor::Linear_Analog_Sensor<LDS2GetName>;
        using LDS3_SENSOR_INFO = cmbtl::linear_analog_sensor::Linear_Analog_Sensor<LDS3GetName>;
        using LDS4_SENSOR_INFO = cmbtl::linear_analog_sensor::Linear_Analog_Sensor<LDS4GetName>;

        using CVT_TEMP_SENSOR_INFO = cmbtl::linear_analog_sensor::Linear_Analog_Sensor<CVTTempGetName>;

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
        LDS1_SENSOR_INFO,
        LDS2_SENSOR_INFO,
        LDS3_SENSOR_INFO,
        LDS4_SENSOR_INFO,
        CVT_TEMP_SENSOR_INFO,
        ANALOG3_SENSOR_INFO,
        ANALOG4_SENSOR_INFO,
        cmbtl::teensy_temp::TEENSY_TEMP_SENSOR_INFO
        >;

        using DAQSensorTestDataType = SensorData<SensorInfoTuple>;

    }
}
#endif