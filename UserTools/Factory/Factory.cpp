#include "Factory.h"
#include "Unity.h"

Tool* Factory(std::string tool) {
Tool* ret=0;

// if (tool=="Type") tool=new Type;
if (tool=="Configuration") ret=new Configuration;
if (tool=="DummyTool") ret=new DummyTool;
if (tool=="Dumper") ret=new Dumper;
if (tool=="FileWriter") ret=new FileWriter;
if (tool=="HKMPMT") ret=new HKMPMT;
if (tool=="JobManager") ret=new JobManager;
if (tool=="LED") ret=new LED;
if (tool=="Monitoring") ret=new Monitoring;
if (tool=="MPMTfakeTrigger") ret=new MPMTfakeTrigger;
if (tool=="MPMT") ret=new MPMT;
if (tool=="Nhits") ret=new Nhits;
if (tool=="RunControl") ret=new RunControl;
if (tool=="SlaveRunControl") ret=new SlaveRunControl;
if (tool=="Sorting") ret=new Sorting;
if (tool=="Trigger") ret=new Trigger;
if (tool=="WindowBuilder") ret=new WindowBuilder;
return ret;
}
