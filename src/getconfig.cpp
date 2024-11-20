
#include <iostream>
#include <Tool.h>
#include "DataModel.h"
#include "DAQInterface.h"

int main(void) {

   DAQInterface daq_intf("./MPMT1.cfg");
   std::string json_data;
   unsigned int timeout = 5000;

   std::cout << "Device name: " << daq_intf.GetDeviceName() << std::endl;
   // get JSON data config from 'configurations' table where config_id == 2
   daq_intf.GetRunConfig(json_data, 2);
   printf("%s\n", json_data.c_str());

   // get JSON data config from 'device_config' table where version == 1 and device == daq_intf.GetDeviceName()
   daq_intf.GetDeviceConfig(json_data, 1);
   printf("%s\n", json_data.c_str());

   // get JSON device config in three steps:
   // 1. get JSON data from 'configurations' table where config_id == 3
   // 2. inside retrieved JSON data get 'version' using daq_intf.GetDeviceName() as key
   // 3. get JSON device config from 'device_config' table using retrieved version and device == daq_intf.GetDeviceName()
   daq_intf.GetDeviceConfigFromRunConfig(json_data, 12);
   printf("%s\n", json_data.c_str());

   Store s;
   s.JsonParser(json_data);
   s.Print();
   printf("==============\n");
   s.JsonParser("{ \"x\": 12, \"y\": 24 }");
   s.Print();

   /*
   // try to handle errors...
   if(!daq_intf.GetDeviceConfigFromRunConfig(json_data, 123))
      printf("ERROR: GetDeviceConfigFromRunConfig with config_id = 123\n");

   // SendRunConfig
   Store tmp;
   tmp.Set("MPMT1", 2);
   tmp.Set("MPMT2", 42);
   tmp >> json_data;
   daq_intf.SendRunConfig(json_data, "sendconfig", "Gennaro", "Config from libDAQInterface", 0, nullptr, timeout);

   // SendDeviceConfig
   Store dev;
   dev.Set("power", 1);
   dev.Set("voltage", 200);
   dev >> json_data;
   daq_intf.SendDeviceConfig(json_data, "Gennaro", "mydevconfig", daq_intf.GetDeviceName(), 0, nullptr, timeout); 
   */

   return 0;

}
